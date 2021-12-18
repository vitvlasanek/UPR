#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int to_1d( const int row, const int col, const int cols ) {
    return col + row * cols;
}


typedef unsigned char byte;

typedef struct TGAHeader_ TGAHeader;

struct TGAHeader_ {
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
};

int tgaheader_width( const TGAHeader * self ) {
    int width = 0;

    memcpy( &width, self->width, 2 );

    return width;
}

int tgaheader_height( const TGAHeader * self ) {
    int height = 0;

    memcpy( &height, self->height, 2 );

    return height;

}

int tgaheader_channels( const TGAHeader * self ) {
    return self->depth / 8;
}
typedef struct TGA_ TGA;

struct TGA_ {
    TGAHeader header;
    byte * data;
};

typedef struct RGBA_ RGBA;

struct RGBA_ {
    byte red;
    byte green;
    byte blue;
    byte alpha;
};



TGA * tga_new( const int width, const int height, const int init_brightness ) {
    TGA * tga = (TGA *)malloc( sizeof( TGA) );
    ALLOCTEST( tga );

    memset( &tga->header, 0, sizeof( TGAHeader ) );
    
    tga->header.image_type = 3;
    tga->header.depth = 8;
    tga->header.descriptor = 1 << 5;

    memcpy( &tga->header.width, &width, 2 );
    memcpy( &tga->header.height, &height, 2 );

    tga->data = (byte *)malloc( width * height * sizeof( byte ) );
    memset( tga->data, init_brightness, width * height * sizeof( byte ) );

    return tga;
}

void tga_free( TGA ** self ) {
    free( (*self)->data );
    (*self)->data = NULL;
    free( (*self) );
    *self = NULL;
}

int tga_width( const TGA * self ) {
    return tgaheader_width( &self->header );
}

int tga_height( const TGA * self ) {
    return tgaheader_height( &self->header );
}

int tga_channels( const TGA * self ) {
    return tgaheader_channels( &self->header );
}

void tga_set_pixel( TGA * self, const int x, const int y, const byte b ) {
    self->data[ to_1d( y, x, tga_width( self ) ) ] = b;
}

void tga_write( const TGA * self, const char * filename ) {
    FILE * f = fopen( filename, "wb" );
    assert( f );

    fwrite( &self->header, sizeof( TGAHeader ), 1, f );

    int res = fwrite( self->data, sizeof( byte ), tga_width( self ) * tga_height( self ) * tga_channels( self ), f );
    assert( res == tga_width( self ) * tga_height( self ) * tga_channels( self ) );

    fclose( f );
}

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

void draw_rect( TGA * tga, const Rect * r, const int color) {
    for ( int y = r->y1; y < r->y2; y++ ) {
        for ( int x = r->x1; x < r->x2; x++ ) {
            tga_set_pixel( tga, x, y, color );
        }
    }
}

Rect digit_coords ( const int offs_x, const int offs_y, int value){
    Rect send;
    if (value == 2 || value == 3)
    {
        send.x1 = offs_x;
        send.y1 = offs_y;
    }
    else if (value == 8)
    {
        send.x1 = offs_x + 30;
        send.y1 = offs_y;
    }
    else if (value == 4 || value == 6 || value == 14 || value == 15)
    {
        send.x1 = offs_x;
        send.y1 = offs_y + 30;
    }
    else if (value == 10 || value == 12 || value == 16 || value == 18 || value == 0 || value == 1)
    {
        send.x1 = offs_x + 30;
        send.y1 = offs_y + 30;
    }
    else if (value == 7 || value == 9 || value == 11 || value == 19){
        send.x1 = offs_x;
        send.y1 = offs_y + 115;
    }
    else
    {
        send.x1 = offs_x + 30;
        send.y1 = offs_y + 115;
    }
    //----------------------------------------------------------------------- konce
    if (value == 4 || value == 6 || value == 8 || value == 16 || value == 18)
    {
        send.x2 = offs_x + 124;
        send.y2 = offs_y + 80;
    }
    else if (value == 10 || value == 12)
    {
        send.x2 = offs_x + 154;
        send.y2 = offs_y + 80;
    }
    else if (value == 2 || value == 3 || value == 8 || value == 9 || value == 14 || value == 15)
    {
        send.x2 = offs_x + 124;
        send.y2 = offs_y + 194;
    }
        else if (value == 5)
    {
        send.x2 = offs_x + 154;
        send.y2 = offs_y + 164;
    }
    else
    {
        send.x2 = offs_x + 124;
        send.y2 = offs_y + 164;
    }
    return send;
}

void watch_draw_time(TGA * self, const int hours, const int minutes){
    int num_pos [4];
    num_pos[0] = hours / 10;
    num_pos[1] = hours % 10;
    num_pos[2] = minutes / 10;
    num_pos[3] = minutes % 10;
    for (int i = 0; i < 4; i++){
        int offs_x = ((i % 2) * 184) + 15;
        int offs_y = ((i / 2) * 224) + 15;
        Rect number_base = {offs_x, offs_y, 154 + offs_x, 194 + offs_y};
        draw_rect (self, &number_base, 255);

        for (int j = 0; j <2; j++){
            Rect box = digit_coords(offs_x, offs_y, (num_pos[i] * 2)+j );
            draw_rect (self, &box, 40);
        }

    }
}

//void watch_draw_time_color( TGA * self, const int hours, const int minutes, const RGBA* fg_color, const RGBA* bg_color ); - přidat


int main(int argc, char *argv[]) {
    /*
    FILE* file = fopen("carmack.tga", "rb");
    assert(file);

    TGAHeader header = {};
    assert(fread(&header, sizeof(TGAHeader), 1, file) == 1);

    printf("Image type: %d, pixel depth: %d\n", header.image_type, header.depth);
    printf("Image width: %d, image height: %d\n", tgaheader_width(&header), tgaheader_height(&header));
    */
    int hours = atoi(argv[1]);
    int minutes = atoi(argv[2]);
    if (argc != 3){
        fprintf(stderr, "Function requires 2 input arguments");
    }

    if ((hours < 0 && hours > 12 )||( minutes < 0 && minutes > 60)){
        fprintf(stderr, "Time %d:%d does not exist\n", hours, minutes);
    }
    int width = 368;
    int height = 448;

    TGA * tga = tga_new( width, height, 40 );

    watch_draw_time(tga, hours, minutes);

    tga_write( tga, "aw.tga" );

    tga_free( &tga );

    return 0;
}

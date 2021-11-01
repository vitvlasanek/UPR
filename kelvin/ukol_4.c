#include <stdio.h>
#include <stdlib.h>

char * vycisti (const char * vstup, const int len){
    char * vystupni_retezec = (char *)malloc(sizeof(char)*len);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if ((int)vstup[i] > 64 && (int)vstup[i] < 91 || (int)vstup[i] > 96 && (int)vstup[i] < 123 )
        {
            vystupni_retezec[j] = vstup [i];
            j = j + 1;
        }
    }
    vystupni_retezec[j] = '\0';
    j = 0;
    return(vystupni_retezec);
}

int main(void){
    int len = 100;
    char vstup[len];
    for (int i = 0; i < len; i++)
    {
        vstup[i] = '0';
    }
    
    char * pointer = vstup;
   // for (int i = 0; i < 100; i++)
/*     {
        if (scanf("%c", &pointer + i) == 1){    
            len = len + 1;
        }
        else{
            break;
        }
    } */

    scanf("%[^\n]s", vstup);
    // for (int i = 0; i < len; i++){
    //     printf("%c", vstup[i]);
    // }

    char * vystup = vycisti(vstup, len);
    printf("%s", vystup);
    free(vystup);
    return 0;
}
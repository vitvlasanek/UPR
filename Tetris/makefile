NAME=tetris
OBJFILES=$(NAME).c mydefs.c movements.c graphics.c colours.c tetrominos.c texts.c
CC=gcc
CFLAGS= -g -fsanitize=address -Wall -Wextra -Wno-unused-variable

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $@ -lSDL2 -lSDL2_ttf
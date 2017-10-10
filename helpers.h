#ifndef helpers
#define helpers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define bool int
#define true 1
#define false 0
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#define clear() printf("\033[H\033[J")
#define sleepms(ms) usleep(ms * 1000)
#define cast(type, value) ((type*) value)

#define NOTHING -1

#define NEW_LINE (char) '\n'
#define ENDS (char) '\0'
#define BLANK ""
#define SPACE (char) 32
#endif

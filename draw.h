#ifndef draw_h
#define draw_h

#include "constants.h"

typedef enum {DRAW_MESSAGE, DRAW_GRAPHIC, DRAW_MAP} OutputType;

typedef struct {
    OutputType type;
    char value[MESSAGE_SIZE];
} Output;

int drawGraphic(char *graphicName);
int drawMessage(char *message);
int draw(Output* output);
int drawArrow(bool newLine);

#endif

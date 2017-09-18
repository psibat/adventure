#ifndef draw_header
#define draw_header

typedef enum {DRAW_MESSAGE, DRAW_GRAPHIC, DRAW_MAP} OutputType;

int drawGraphic(char *graphicName);
int drawMessage(char *message);
int draw(void *output, int outputType);
int drawArrow(bool newLine);

#endif

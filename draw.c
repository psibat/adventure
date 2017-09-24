#include "helpers.h"
#include "draw.h"

int drawGraphic(char *graphicName) {
    char *fileName = malloc(strlen(graphicName) + (sizeof(char) * GFX_LEN)); 
    strcpy(fileName, GFX_DIR);
    strcat(fileName, graphicName);
    strcat(fileName, GFX_EXT);
    FILE* file = fopen(fileName, "r"); 
    char line[LINE_SIZE];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); 
    }

    fclose(file);

    return 0;
}

int drawMessage(char message[]) {
    if (message[0] != 10 && message[0] != ENDS) {
        printf("%c", message[0]);
        fflush(stdout);
        int i = 0;
        int lineLength = 1;
        for (i = 1; i < MESSAGE_SIZE && message[i] != ENDS; i++, lineLength++) {   
            switch (message[i]) {
                case '!':
                case '.':
                case '?':
                    sleepms(300);
                    break;
                case NEW_LINE:
                    sleepms(200);
                    lineLength = 0;
                    break;
                case ',':
                    sleepms(100);
                    break;
            }

            sleepms(100);

            if (message[i] != 10) {
                printf("%c", message[i]);
                fflush(stdout);
                if (lineLength == LINE_SIZE) {
                    printf("%c", NEW_LINE);
                    lineLength = 0;
                }
            }
        }
    }
    return 0;
}

int drawArrow(bool newLine) {
    if (newLine) printf("%c", NEW_LINE);
    printf("> ");
    fflush(stdout);

    return 0;
}

int draw(Output* output) { 
    
    switch (output->type) {
        case DRAW_MESSAGE:
            drawMessage((char *) output->value);
            break;
        case DRAW_GRAPHIC:
            drawGraphic(output->value);
            break;
        case DRAW_MAP:
            break;
        
    }

    drawArrow(true);

    return 0;
}

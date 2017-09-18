#include "helpers.h"
#include "game.h"
#include "constants.h"

#include "parser.h"
#include "draw.h"

void input(char *command) {
    fgets (command, MESSAGE_SIZE + 1, stdin);
}

int process(char *command, char **tokens, void **output) {
    char *message;
    
    message = malloc(sizeof(char) * MESSAGE_SIZE + 1);
    *output = message;

    getTokens(tokens, command);

    strcpy(message, tokens[0]);
    size_t len = strlen(message);
    message[len] = NEW_LINE;
    message[len + 1] = ENDS;

    int i; 
    for (i = 1; i < COMMAND_SIZE && tokens[i][0] != ENDS; i++) {
        strcat(message, tokens[i]);
        len = strlen(message);
        message[len] = NEW_LINE;
        message[len + 1] = ENDS;
    }

    return DRAW_MESSAGE;
}

int main() {
    // Pointer to output
    void *output;
    // Type of output (how to draw it, @TODO enum)
    int outputType;
    // The input as a string
    char *command = malloc(sizeof(char) * MESSAGE_SIZE + 1);
    // The input separated into words
    char **words = malloc(sizeof(char *) * COMMAND_SIZE);
    // Allocating space for words
    int i;
    for (i = 0; i < COMMAND_SIZE; i++) {
        words[i] = malloc(sizeof(char) * WORD_SIZE + 1);
    }

    Action *actions = malloc(sizeof(Action) * ACTION_SIZE);

    loadActions(actions);

    printf("%d\n", actions[0].method);
    printf("%d\n", actions[1].method);
    //clear();

    // Load welcome graphic, @TODO Graphic constants
    drawGraphic("welcome");
    drawArrow(false);

    while (true) {
        input(command);
        outputType = process(command, words, &output);
        draw(output, outputType);
        free(output);
    }

    return 0;
}

//@TODO Headers, redraw struct, literally everything else
//  Graphics
//      Fixed width ascii  art
//  Areas of the room
//      * North side / wall
//      * South side / wall
//      * East side / wall
//      * West side / wall
//      Position / Facing
//      Cones of view
//      Corners
//  Alchemy
//      Matter: R, G, B and Alpha prima materia
//      Code: ASCII - 87 as a big number (1st num * 1000 next 2nd num * 100 etc), in hex
//      Hidden items (Like half values and double)
//  Tranqs 
//      Endurance? 
//      Enemies facing different directions
//      Different amounts of tranq
//      Action points
//  Error message
//      Treat error as command word
//

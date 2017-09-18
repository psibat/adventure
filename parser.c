#include "helpers.h"
#include "constants.h"
#include "parser.h"

#define DELIMITERS " \n"


void getTokens(char **words, char *command) {
    char *token;

    token = strtok(command, DELIMITERS);
    int i;
    for(i = 0; i < COMMAND_SIZE && token != NULL; i++, token = strtok(NULL, DELIMITERS)) {
        strcpy(words[i], token);
    }

    words[i][0] = ENDS;
}



int loadActions(Action *actions) {
    Action *look = malloc(sizeof(Action));
    look->method = LOOK;
    actions[0] = *look;
    Action *fart = malloc(sizeof(Action));
    fart->method = FART;
    actions[1] = *fart;


    return 0;
}

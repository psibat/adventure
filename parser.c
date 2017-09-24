#include "helpers.h"
#include "constants.h"
#include "parser.h"

#define DELIMITERS " \n"

Action *ACTIONS;

void parse(Command *command) {
    // Get user input
    char message[MESSAGE_SIZE+1];
    fgets (message, MESSAGE_SIZE, stdin);

    //Split user input
    char tokens[COMMAND_SIZE][WORD_SIZE+1] = {0};
    getTokens(tokens, message);

    Word words[COMMAND_SIZE+1] = {0};
    words[0] = getWord(tokens[0], ACTIONS);

    Action* action;

    if (words[0].type == ACTION) {
        action = words[0].value;
    }

    bool validGrammar = false;
    WordType* grammar; 
    bool loop = true;
    int i, j;
    // Loop through words
    for(i = 0; i < COMMAND_SIZE+1 && loop; i++) {
        words[i+1] = getWord(tokens[i+1], ACTIONS);

        if (words[i+1].type == NOTHING) {
            if (i == 0) {
                words[1] = (Word) {.type=LACUNA};       
            } else {
                break;
            }
        }

        // Loop through the grammars checking the type at n[i]
        for (j = 0; j < GRAMMAR_SIZE && loop; j++) {
            if (((Action*) words[0].value)->grammars[j][i] == NOTHING && i == 0) {
                    break;
            } else if (((Action*) words[0].value)->grammars[j][i] == words[i+1].type) {
                if (((Action*) words[0].value)->grammars[j][i+1] == NOTHING) {
                    validGrammar = true;
                    grammar = ((Action*) words[0].value)->grammars[j]; 
                }
            }
        }
    }

    command->action = action;
    command->grammar = grammar;
    memcpy(command->args, words, sizeof(Word) * COMMAND_SIZE);
}

void getTokens(char tokens[COMMAND_SIZE][WORD_SIZE+1], char *message) {
    char *token;

    token = strtok(message, DELIMITERS);
    int i;
    for(i = 0; i < COMMAND_SIZE && token != NULL; i++, token = strtok(NULL, DELIMITERS)) {
        strcpy(tokens[i], token);
    }

    tokens[i][0] = ENDS;

}


Word getWord(char input[], Action action[]) {
    
    char *word = input;
    Word returnValue;
    bool found = false;


    if (strcmp(BLANK, word) == 0) {
        found = true;
        returnValue.type = NOTHING;
    }
    int i;
    int j;
    for(i = 0; i < ACTION_SIZE && !found; i++) {
        for (j = 0; j < DIFF_WORD_OPTIONS && !found; j++) {
         
            if (action[i].words[j][0] != ENDS && strcmp(word, action[i].words[j]) == 0) {
                found = true;
                returnValue.type = ACTION;
                returnValue.value = &action[i];
            }
        }
    }

    if (!found) {
        returnValue.type = UNKNOWN;
    }

    return returnValue;
}

void doFart(Output* output, Command* command) {
    output->type = DRAW_MESSAGE;
    strcpy(output->value, "You fart");
}

int loadActions() {
 ACTIONS = malloc(sizeof(Action) * ACTION_SIZE);
    Action look = {
        .actionID = LOOK,
        .words = {"look", "examine", "describe", BLANK },
        .grammars = {
            {OBJECT},
            {LACUNA},
            {NOTHING},
        },
    };
    ACTIONS[0] = look;
    Action fart = {
        .actionID = FART,
        .words = {"fart", BLANK},
        .grammars = {{LACUNA, -1}, {NOTHING, -1}},
        .method = &doFart
    };
    ACTIONS[1] = fart;

    return 0;
}

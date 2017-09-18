#ifndef parser
#define parser

typedef enum {ACTION, OBJECT, DIRECTION, WORDTYPE_SIZE} WordType;
typedef enum {
    LOOK,
    FART,
    ACTION_SIZE
} ActionMethod;

typedef struct {
    char words[GRAMMAR_SIZE][WORD_SIZE];
    WordType grammars[GRAMMAR_SIZE][COMMAND_SIZE];
    ActionMethod method;
} Action;
void getTokens(char **words, char *command);
int loadActions(Action *actions);

#endif

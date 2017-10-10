#ifndef parser
#define parser

#include "draw.h" 

#define COMMAND_SIZE 10
#define WORD_SIZE 45

#define DIFF_WORD_OPTIONS 10
#define GRAMMAR_SIZE 5

typedef struct _Action Action;
typedef struct _Command Command;

typedef enum {LACUNA, ACTION, OBJECT, DIRECTION, SENTENCE, UNKNOWN, WORDTYPE_SIZE} WordType;
typedef enum {NPC, ITEM} ObjectType;
typedef enum {
    ERROR,
    FART,
    LOOK,
    ACTION_SIZE
} ActionMethod;

struct _Action{
    char words[DIFF_WORD_OPTIONS][WORD_SIZE];
    WordType grammars[GRAMMAR_SIZE][COMMAND_SIZE];
    void (*method)(Output*, Command*);
};

typedef struct {
    ObjectType type; 
    char name[WORD_SIZE]; 
    char description[WORD_SIZE];
} Object;

typedef struct {
    Object base;
    int health; 
} NPCObject;

typedef struct {
    Object base;
    int health;
} Item;


typedef struct {
    WordType type;
    void* value;
} Word;

struct _Command{
    Action* action;
    Word args[COMMAND_SIZE+1];
    WordType* grammar;
};

extern Action *ACTIONS;

void getTokens(char tokens[COMMAND_SIZE][WORD_SIZE+1], char *command);
Word getWord(char word[], Action action[]);
int loadActions();
void parse(Command* command);
#endif

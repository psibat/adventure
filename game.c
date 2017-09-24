#include "helpers.h"
#include "game.h"
#include "constants.h"

#include "parser.h"
#include "draw.h"

int main() {
    Output* output = malloc(sizeof(Output));
    Command* command = malloc(sizeof(Command));
    loadActions();

    //clear();

    // Load welcome graphic, @TODO Graphic constants
    drawGraphic("welcome");
    drawArrow(false);

    parse(command);
    printf("Action word: %s\n", command->action->words[0]);
    printf("Grammar: %d-%d\n", command->grammar[0], command->grammar[1]);
    printf("Grammar: %d, %d\n", command->action->grammars[0][0], command->action->grammars[0][1]);
    command->action->method(output, command);
    drawArrow(false);
    while (true) {
        parse(command);
        command->action->method(output, command);
        draw(output);
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
//  Characters
//      Miss CEO / Missy Ozmand
//      Prof. Philo Panopolis
//

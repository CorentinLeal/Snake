#include <allegro.h>
#include <stdio.h>
#include "launch.h"

int main(){
    Launch *launch = initLauch();
    play(launch);
    return 0;
} END_OF_MAIN() ;

Launch* initLauch() {
    Launch *launch = malloc(sizeof(Launch));
    launch -> game = initGame();
    launch -> draw = initDraw();
    return launch;
}

int play(Launch *launch) {
    Game* game = launch-> game;
    Draw* draw = launch-> draw;
    int colision = 0;
    while (colision == 0) {
        renderMap(game, draw);
        rest(250);
        colision = gameRound(launch -> game);
    }
}

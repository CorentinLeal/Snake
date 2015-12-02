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
    while (1) {
        gameRound(launch -> game);
        renderMap(game, draw);
        rest(500);
    }
}

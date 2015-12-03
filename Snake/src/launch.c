#include <allegro.h>
#include <stdio.h>
#include "launch.h"

int main(){
    Launch *launch = initLaunch();
    play(launch);
    return 0;
} END_OF_MAIN() ;

Launch* initLaunch() {
    Launch *launch = malloc(sizeof(Launch));
    launch -> game = initGame();
    launch -> draw = initDraw();
   // renderMap(launch -> game -> field, launch->draw);
    return launch;
}

int play(Launch *launch) {
    Game* game = launch-> game;
    Draw* draw = launch-> draw;
    int colision = 0;
    while (colision == 0) {
        renderGame(game, draw);
        rest(54);
        colision = gameRound(launch -> game);
    }
    return 0;
}

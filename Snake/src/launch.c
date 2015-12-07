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
    prepareMap(launch ->game->field, launch->draw->mapBuffer, launch->draw->tiles);
    return launch;
}

int play(Launch *launch) {
    Game* game = launch-> game;
    Draw* draw = launch-> draw;
    int gameOver = 0;
    int gameReturn;
    while (!gameOver) {
        renderGame(game, draw);
        rest(250);
        gameReturn = gameRound(launch -> game);
        if (gameReturn == 1) {
            gameOver = 1;
        } else if (gameReturn == 2) {
            gamePause(launch);
        }
    }
    return 0;
}

int gamePause(Launch* launch) {
    renderPause(launch -> draw);
    pause();
    return 0;
}

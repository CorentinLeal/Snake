#include <allegro.h>
#include <stdio.h>
#include "launch.h"

int main(){
    Launch *launch = initLaunch();
    play(launch);
    return 0;
} END_OF_MAIN() ;

Launch* initLaunch() {
    allegroInit();
    Launch *launch = malloc(sizeof(Launch));
    launch -> draw = initDraw();
    launch -> game = initGame();
    prepareMap(launch ->game->field, launch->draw->mapBuffer, launch->draw->tiles);
    return launch;
}

int play(Launch *launch) {
    waitStart(launch);
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

int waitStart(Launch* launch) {
    renderMenu(launch -> draw);
    int waitStart = 0;
    while (!waitStart) {
        if (keypressed() && readkey() >> 8 == KEY_ENTER) {
            waitStart = 1;
        }
    }
    return 0;
}

int allegroInit() {
    if(allegro_init() != 0){
        return 1;
    }

    install_timer();
    install_keyboard();

    return 0;
}

#ifndef LAUNCH_H_INCLUDED
#define LAUNCH_H_INCLUDED
#include "draw.h"
#include "game.h"

typedef struct Launch Launch;


typedef struct Launch {
    Game* game;
    Draw* draw;
}Launch;

Launch* initLaunch();
int play (Launch* launch);
int gamePause(Launch *launch);
int allegroInit();
int waitStart(Launch *launch);


#endif // LAUNCH_H_INCLUDED

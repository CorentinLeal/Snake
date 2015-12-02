#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "game.h"

#define TILE_COUNT 3 // Ne peut pas être déclaré comme constante

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;
static const int SCREEN_DEPTH = 32;


static const int TILE_HEAD = 0;
static const int TILE_BODY = 1;
static const int TITE_APPLE_CLASSIC = 2;

////////////////////////////////////

typedef struct Draw Draw;

typedef struct Draw {

    BITMAP* doubleBuffer;
    BITMAP* tiles[TILE_COUNT];

}Draw;

Draw* initDraw();
int renderMap (Game* game, Draw *draw);
int renderSnake(SnakeHead * snakeHead, BITMAP* doubleBuffer, BITMAP* tiles[TILE_COUNT]);
int renderApple(Apple* apple, BITMAP* doubleBuffer, BITMAP* tiles[TILE_COUNT]);
int showScreen (BITMAP* doubleBuffer);

#endif // DRAW_H_INCLUDED

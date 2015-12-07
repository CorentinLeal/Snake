#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "game.h"
#include "map.h"
#define TILE_COUNT 5 // Ne peut pas être déclaré comme constante

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 600;
static const int SCREEN_DEPTH = 32;


static const int TILE_HEAD = 0;
static const int TILE_BODY = 1;
static const int TILE_APPLE_CLASSIC = 2;
static const int TILE_APPLE_MAGIC = 3;
static const int TILE_WALL = 4;
static const int TILE_PAUSE = 5;

////////////////////////////////////

typedef struct Draw Draw;

typedef struct Draw {

    BITMAP* doubleBuffer;
    BITMAP* mapBuffer;
    BITMAP* tiles[TILE_COUNT];

}Draw;

Draw* initDraw();
int renderGame (Game* game, Draw *draw);
int renderPause (Draw *draw);
int renderSnake(SnakeHead * snakeHead, BITMAP* doubleBuffer, BITMAP* tiles[TILE_COUNT]);
int renderApple(Apple* apple, BITMAP* doubleBuffer, BITMAP* tiles[TILE_COUNT]);
int prepareMap (Map* field, BITMAP* mapBuffer, BITMAP* tiles[TILE_COUNT]);
int renderMap (BITMAP* doubleBuffer, BITMAP* mapBuffer);
int showScreen (BITMAP* doubleBuffer);

#endif // DRAW_H_INCLUDED

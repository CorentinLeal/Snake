#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED


static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;
static const int SCREEN_DEPTH = 32;

static const int TILE_COUNT = 3;

static const int TILE_HEAD = 0;
static const int TILE_BODY = 1;

////////////////////////////////////

typedef struct Draw Draw;

typedef struct Draw {

    BITMAP* doubleBuffer;
    BITMAP* tiles[TILE_COUNT];

}Draw;

Draw* initDraw();
int renderMap (Game* game);
int renderSnake(SnakeHead * snakeHead, BITMAP* doubleBuffer, TILES* tiles[TILE_COUNT]);
int showScreen (BITMAP* doubleBuffer);

#endif // DRAW_H_INCLUDED

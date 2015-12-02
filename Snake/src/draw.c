#include <stdio.h>
#include <allegro.h>
#include "draw.h"

/**
* Create and return a Draw.
*/
Draw* initDraw () {
    Draw* draw = malloc(sizeof(Draw));

    set_color_depth(SCREEN_DEPTH);
    set_gfx_mode (GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

    draw -> doubleBuffer = create_bitmap (SCREEN_WIDTH, SCREEN_HEIGHT);
    if (draw -> doubleBuffer == NULL){
        fprintf (stderr, "double buffer could not be created. program terminated\n");
        exit(1);
     }

    char tile_filename[64];

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_HEAD);
    draw -> tiles[TILE_HEAD] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_BODY);
    draw -> tiles[TILE_BODY] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_APPLE);
    draw -> tiles[TILE_BODY] = load_bitmap (tile_filename, NULL);

    if (draw -> tiles[TILE_HEAD] == NULL){
        fprintf (stderr, "tile%d.png could not be loaded. program terminated\n", TILE_HEAD);
        exit(1); // terminate program
    } else if (draw -> tiles[TILE_BODY] == NULL){
        fprintf (stderr, "tile%d.png could not be loaded. program terminated\n", TILE_BODY);
        exit(1); // terminate program
    } else if (draw -> tiles[TILE_APPLE] == NULL){
        fprintf (stderr, "tile%d.png could not be loaded. program terminated\n", TILE_BODY);
        exit(1); // terminate program
    }

    return draw;
}

int renderMap (Game* game, Draw* draw){

    SnakeHead* snakeHead = game -> snakeHead;
    Apple* apple = game -> apple;

    clear_bitmap(draw -> doubleBuffer);

    renderApple(apple, draw -> doubleBuffer, draw -> tiles)
    renderSnake(snakeHead, draw -> doubleBuffer, draw -> tiles);
    showScreen(draw -> doubleBuffer);
    return 0;
}

int renderSnake(SnakeHead * snakeHead, BITMAP* doubleBuffer, BITMAP* tiles[TILE_COUNT]){
    int mx = snakeHead -> x;
    int my = snakeHead -> y;
    int requestedTile = TILE_HEAD;

    int tileX = mx * tiles[requestedTile]->w;
    int tileY = my * tiles[requestedTile]->h;

   blit (tiles[requestedTile],
         doubleBuffer,
         0, 0,
         tileX, tileY,
         tiles[requestedTile]->w, tiles[requestedTile]->h);

    SnakeBody *snakeBody = snakeHead -> nextElement;
    requestedTile = TILE_BODY;

    while (snakeBody != NULL) {
        mx = snakeBody -> x;
        my = snakeBody -> y;

        tileX = mx * tiles[requestedTile]->w;
        tileY = my * tiles[requestedTile]->h;

        blit (tiles[requestedTile],
            doubleBuffer, 0, 0,
            tileX, tileY,
            tiles[requestedTile]->w,
            tiles[requestedTile]->h);

        snakeBody = snakeBody -> nextElement;

    }
    return 0;
}

int renderApple(Apple* apple, BITMAP* doubleBuffer, BITMAP* tiles[TILE_COUNT]) {
    int mx = apple -> x;
    int my = apple -> y;
    int requestedTile = TILE_APPLE;

    int tileX = mx * tiles[requestedTile]->w;
    int tileY = my * tiles[requestedTile]->h;

   blit (tiles[requestedTile],
         doubleBuffer,
         0, 0,
         tileX, tileY,
         tiles[requestedTile]->w, tiles[requestedTile]->h);
}

int showScreen (BITMAP* doubleBuffer){

     // blit the whole double buffer to the screen
     blit (doubleBuffer,     // source Allegro BITMAP*
           screen,           // destination Allegro BITMAP*
           0, 0,             // source x,y
           0, 0,             // destination x, y
           doubleBuffer->w,  // destination width
           doubleBuffer->h); // destination height

    return 0;
}

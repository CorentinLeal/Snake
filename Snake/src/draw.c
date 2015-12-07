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

    draw -> mapBuffer = create_bitmap (SCREEN_WIDTH, SCREEN_HEIGHT);

    if (draw -> doubleBuffer == NULL){
        fprintf (stderr, "double buffer could not be created. program terminated\n");
        exit(1);
     }

    char tile_filename[64];

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_HEAD);
    draw -> tiles[TILE_HEAD] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_BODY);
    draw -> tiles[TILE_BODY] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_APPLE_CLASSIC);
    draw -> tiles[TILE_APPLE_CLASSIC] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_APPLE_MAGIC);
    draw -> tiles[TILE_APPLE_MAGIC] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_WALL);
    draw -> tiles[TILE_WALL] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_PAUSE);
    draw -> tiles[TILE_PAUSE] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_MENU);
    draw -> tiles[TILE_MENU] = load_bitmap (tile_filename, NULL);

    sprintf (tile_filename, "Snake/resources/tile%d.tga", TILE_PLAY);
    draw -> tiles[TILE_PLAY] = load_bitmap (tile_filename, NULL);

    if (draw -> tiles[TILE_HEAD] == NULL){
        fprintf (stderr, "tile%d.tga could not be loaded. program terminated\n", TILE_HEAD);
        exit(1); // terminate program
    } else if (draw -> tiles[TILE_BODY] == NULL){
        fprintf (stderr, "tile%d.tga could not be loaded. program terminated\n", TILE_BODY);
        exit(1); // terminate program
    } else if (draw -> tiles[TILE_APPLE_CLASSIC] == NULL){
        fprintf (stderr, "tile%d.tga could not be loaded. program terminated\n", TILE_APPLE_CLASSIC);
        exit(1); // terminate program
    }  else if (draw -> tiles[TILE_PAUSE] == NULL){
        fprintf (stderr, "tile%d.tga could not be loaded. program terminated\n", TILE_PAUSE);
        exit(1); // terminate program
    } else if (draw -> tiles[TILE_MENU] == NULL){
        fprintf (stderr, "tile%d.tga could not be loaded. program terminated\n", TILE_MENU);
        exit(1); // terminate program
    } else if (draw -> tiles[TILE_PLAY] == NULL){
        fprintf (stderr, "tile%d.tga could not be loaded. program terminated\n", TILE_PLAY);
        exit(1); // terminate program
    }

    return draw;
}

int renderGame (Game* game, Draw* draw){

    SnakeHead* snakeHead = game -> snakeHead;
    Apple* apple = game -> apple;

    clear_bitmap(draw -> doubleBuffer);

    renderMap(draw->doubleBuffer, draw->mapBuffer);

    renderApple(apple, draw -> doubleBuffer, draw -> tiles);
    renderSnake(snakeHead, draw -> doubleBuffer, draw -> tiles);

    writeScore(game ->score, draw ->doubleBuffer);
    writeLife(game->snakeHead->health, draw->doubleBuffer);

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

    int requestedTile;
    if (apple -> isMagic) {
        requestedTile = TILE_APPLE_MAGIC;
    } else {
        requestedTile = TILE_APPLE_CLASSIC;
    }

    int tileX = mx * tiles[requestedTile]->w;
    int tileY = my * tiles[requestedTile]->h;

   blit (tiles[requestedTile],
         doubleBuffer,
         0, 0,
         tileX, tileY,
         tiles[requestedTile]->w, tiles[requestedTile]->h);
    return 0;
}
 int prepareMap (Map *map, BITMAP* mapBuffer, BITMAP* tiles[TILE_COUNT]) {
    int x, y, mx, my, tileX, tileY;
    int requestedTile = TILE_WALL;
    for (x=0; x<MAP_WIDTH; x++) {
        for (y=0; y<MAP_HEIGHT; y++) {
            if (map -> field[x][y] == 1) {
                mx=x;
                my=y;
                tileX = mx * tiles[requestedTile]->w;
                tileY = my * tiles[requestedTile]->h;

                blit (tiles[requestedTile],
                     mapBuffer,
                     0, 0,
                     tileX, tileY,
                     tiles[requestedTile]->w, tiles[requestedTile]->h);
            }
        }
    }

    return 0;
 }

int renderMap(BITMAP* doubleBuffer, BITMAP* mapBuffer) {
    blit (mapBuffer,
          doubleBuffer,
          0, 0,
          0, 0,
          mapBuffer->w,
          mapBuffer->h);
    return 0;
}

int renderPause(Draw *draw) {

    blit (draw ->tiles[TILE_PAUSE],
       draw->doubleBuffer,
       0, 0,
       0, 0,
       draw ->tiles[TILE_PAUSE]->w,
       draw ->tiles[TILE_PAUSE]->h);
    showScreen(draw->doubleBuffer);
    return 0;
}

int writeScore(int score, BITMAP* doubleBuffer) {
    char* scoreOutput = "Score : ";
    char finalOutput[11];
    sprintf(finalOutput, "%s %d", scoreOutput, score);
    textout_ex(doubleBuffer, font, finalOutput, 5, SCREEN_HEIGHT - 20,
		 makecol(255, 255, 255), -1);
		 return 0;
}

int writeLife (int life, BITMAP* doubleBuffer) {
    char* lifeOutput = "Vie : ";
    char finalOutput[11];
    sprintf(finalOutput, "%s %d", lifeOutput, life);
    textout_ex(doubleBuffer, font, finalOutput, 5, SCREEN_HEIGHT - 40,
		 makecol(255, 255, 255), -1);
		 return 0;
}

int renderMenu(Draw* draw) {
    BITMAP* menu = draw->tiles[TILE_MENU];
    BITMAP* buttonplay = draw->tiles[TILE_PLAY];
    blit(menu,draw->doubleBuffer,0,0,0,0,menu->w,menu->h);
    blit(buttonplay,draw->doubleBuffer,0,0,235,290,buttonplay->w,buttonplay->h);
    showScreen(draw->doubleBuffer);
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

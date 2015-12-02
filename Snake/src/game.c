#include <allegro.h>
#include <stdio.h>
#include "game.h"
#include "directionVariables.h"

// Initialise the game
Game* initGame(){
    Game *game = malloc(sizeof(Game));
    game -> snakeHead = initSnake();
    allegroInit();
    return game;
}

int allegroInit() {
    if(allegro_init() != 0){
        return 1;
    }

    install_timer();
    install_keyboard();

    return 0;
}

// main function of the game
int gameRound(Game *game){
    SnakeHead *snakeHead = game -> snakeHead;
    int currentDirection = snakeHead->direction;


    while (keypressed()) {

        int lastKey = readkey();

        if (lastKey >> 8 == KEY_DOWN && currentDirection != UP) {
            printf("You pressed down\n");
            snakeHead->direction = DOWN;
        }else if (lastKey >> 8 == KEY_UP && currentDirection != DOWN){
            printf("You pressed up\n");
            snakeHead->direction = UP;
        }else if (lastKey >> 8 == KEY_LEFT && currentDirection != RIGHT){
            printf("You pressed left\n");
            snakeHead->direction = LEFT;
        }else if (lastKey >> 8 == KEY_RIGHT && currentDirection != LEFT){
            printf("You pressed right\n");
            snakeHead->direction = RIGHT;
        }
    }
    printf("DIRECTION = %d \n", snakeHead -> direction);
    snakeMove(snakeHead);
    printf ("Tête : x=%d, y=%d \n", snakeHead -> x, snakeHead -> y);
    SnakeBody *snakeBody = snakeHead -> nextElement;
    int i = 1;
    while (snakeBody != NULL) {
        printf("Part %d : x=%d , y=%d \n", i, snakeBody -> x, snakeBody -> y);
        i++;
        snakeBody = snakeBody -> nextElement;
    }
    return 0;
}

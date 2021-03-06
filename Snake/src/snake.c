#include <allegro.h>
#include <stdio.h>
#include "snake.h"
#include "directionVariables.h"
#include "map.h"

/**
* Cr�e et retourne un SnakeBody.
* @param    x : la position en x du SnakeBody
*           y : la position en y du SnakeBody
*/
SnakeBody *newSnakeBody (int x, int y) {
    SnakeBody *snakeBody = malloc(sizeof(SnakeBody));
    snakeBody -> x = x;
    snakeBody -> y = y;
    snakeBody ->nextElement = NULL;
    return snakeBody;
}

/**
* Fait avancer le snakeHead en param�tre en fonction de sa direction.
*/
int headMove(SnakeHead *snakeHead){
    int direction = snakeHead -> direction;
    if (direction == UP) {
        int y = snakeHead -> y;
        if (y-1 >= 0) {
            snakeHead -> y = y-1;
        }
        else {
            snakeHead -> y = MAP_HEIGHT-1;
        }
    }
    else if (direction == DOWN) {
        int y = snakeHead -> y;
        if (y+1 < MAP_HEIGHT) {
            snakeHead -> y = y+1;
        }
        else {
            snakeHead -> y = 0;
        }
    }
    else if (direction == RIGHT) {
        int x = snakeHead -> x;
        if (x+1 < MAP_WIDTH) {
            snakeHead -> x = x+1;
        }
        else {
            snakeHead -> x = 0;
        }
    }
    else if (direction == LEFT) {
        int x = snakeHead -> x;
        if (x-1 >= 0) {
            snakeHead -> x = x-1;
        }
        else {
            snakeHead -> x = MAP_WIDTH-1;
        }
    }
    return 0;
}


/**
* Fait avancer le snake.
*/
int snakeMove (SnakeHead *snakeHead) {
    int previousX = snakeHead -> x;
    int previousY = snakeHead -> y;
    // on commence par faire bouger la tete
    headMove(snakeHead);
    int headX = snakeHead -> x;
    int headY = snakeHead -> y;
    int newX;
    int newY;
    SnakeBody *snakeBody = snakeHead -> nextElement;
    // Si besoin, faire grandir le snake
    if (snakeBody == NULL && snakeHead -> growth > 0) {
        snakeHead -> nextElement = newSnakeBody(previousX, previousY);
        snakeHead -> growth--;
    } else {
        SnakeBody *snakeTail = malloc(sizeof(SnakeBody));
        while (snakeBody != NULL) {
            newX = previousX;
            newY = previousY;
            previousX = snakeBody -> x;
            previousY = snakeBody -> y;
            snakeBody -> x = newX;
            snakeBody -> y = newY;
            if (newX == headX && newY == headY) {
                return 1;
            }
            if (snakeBody -> nextElement == NULL) {
                snakeTail = snakeBody;
            }
            snakeBody = snakeBody -> nextElement;
        }
        if (snakeHead -> growth > 0) {
            if (previousX == headX && previousY == headY) {
                return 1;
            }
            else {
                snakeTail-> nextElement = newSnakeBody(previousX, previousY);
                snakeHead -> growth--;
            }
        }
    }
    return 0;
}

/**
* Initialise un snake.
*/
SnakeHead* initSnake () {
    SnakeHead *snakeHead = malloc(sizeof(SnakeHead));
    snakeHead -> x = 6;
    snakeHead -> y = 1;
    snakeHead -> direction = RIGHT;
    snakeHead -> growth = baseSize;
    snakeHead -> health = baseHealth;
    snakeHead -> nextElement = NULL;
    return snakeHead;
}

/**
* Retire une vie
*/
int looseLife(SnakeHead* snakeHead) {
    snakeHead -> x = 6;
    snakeHead -> y = 1;
    snakeHead -> direction = RIGHT;
    snakeHead -> growth = baseSize;
    snakeHead -> health--;
    snakeHead -> nextElement = NULL;
    return 0;
}

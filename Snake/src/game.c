#include <allegro.h>
#include <stdio.h>
#include "game.h"
#include "directionVariables.h"

// Initialise the game
Game* initGame(){
    Game *game = malloc(sizeof(Game));
    game -> snakeHead = initSnake();
    game -> field = initMap(1);
    game -> apple = placeApple(game -> snakeHead, game -> field);
    game -> score = 0;
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
    int colision;
    int gameOver = 0;

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
        }else if(lastKey >> 8 == KEY_P) {
            return 2;
        }

    }
    printf("DIRECTION = %d \n", snakeHead -> direction);
    colision = snakeMove(snakeHead);
    printf ("Tête : x=%d, y=%d \n", snakeHead -> x, snakeHead -> y);
    SnakeBody *snakeBody = snakeHead -> nextElement;
    int i = 1;
    while (snakeBody != NULL) {
        printf("Part %d : x=%d , y=%d \n", i, snakeBody -> x, snakeBody -> y);
        i++;
        snakeBody = snakeBody -> nextElement;
    }

    if (colision || checkWallColision(game)) {
        if (snakeHead -> health > 1) {
            looseLife(snakeHead);
        }
        else {
            gameOver = 1;
        }
    }

    colisionApple(game);

    return gameOver;
}

int checkWallColision(Game* game) {
    SnakeHead* snakeHead = game -> snakeHead;
    Map *map = game -> field;
    return map -> field [snakeHead -> x] [snakeHead -> y];
}
int colisionApple(Game* game){

    SnakeHead* snake = game -> snakeHead;
    Apple* apple = game -> apple;
    int appleX = apple -> x;
    int appleY = apple -> y;
    int snakeX = game -> snakeHead -> x;
    int snakeY = game -> snakeHead -> y;

    if((appleX == snakeX) && (appleY == snakeY)){

        snake -> growth = apple -> point;
        free(apple);
        game -> apple = placeApple(snake, game ->field);
        game -> score += apple -> point;
    }

    return 0;

}


Apple* placeApple(SnakeHead* snakeHead, Map* field){
    int placed = 0;
    SnakeBody *element = snakeHead -> nextElement;
    Apple *apple = initApple();

    while(placed==0){
        if (field->field [apple->x] [apple->y])  {
            free(apple);
            apple = initApple();
        }
        else if(apple -> x == snakeHead -> x && apple -> y == snakeHead -> y){
            free(apple);
            apple = initApple();
        }else if(element != NULL){
            if(apple -> x == element -> x && apple -> y == element -> y){
                free(apple);
                apple = initApple();
            }else if (element -> nextElement == NULL){
                placed = 1;
            }
            element = element -> nextElement;
        }else{
            placed =1;
        }
    }
    return apple;
}

int pause () {
    int pauseEnd = 0;
    while (!pauseEnd) {
        if (keypressed() && readkey() >> 8 == KEY_P) {
            printf("lol");
            pauseEnd = 1;
        }
    }
    return 0;
}

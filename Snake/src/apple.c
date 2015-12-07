#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "apple.h"
#include "map.h"

Apple* initApple(){
    Apple* apple = malloc(sizeof(Apple));
    srand(time(NULL));
    apple -> x = rand() % MAP_WIDTH;
    apple -> y = rand() % MAP_HEIGHT;
    int point = rand() % MAGIC_APPLE_RATE;

    if(point == 0){
        apple -> point = POINT_MAGIC;
        apple -> isMagic = 1;
    }else{
        apple -> point = POINT_CLASSIC;
        apple -> isMagic = 0;
    }

    return apple;
}

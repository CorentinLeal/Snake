#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "apple.h"
#include "map.h"

Apple* initApple(){
    Apple* apple = malloc(sizeof(Apple));
    apple -> x = rand() % MAP_WIDTH;
    apple -> y = rand() % MAP_HEIGHT;
    int point = rand() % 10;
    if(point == 0){
        apple -> point = POINT_MAGIC;
    }else{
        apple -> point = POINT_CLASSIC;
    }
}

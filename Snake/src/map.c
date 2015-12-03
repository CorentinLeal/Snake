#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"


Map* initMap(int walls){
    Map* map = malloc(sizeof(Map));

    int i;
    int j;

    if(walls==1){
        for(i=0; i<MAP_WIDTH; i++){

            for(j=0; j<MAP_HEIGHT; j++){
                if(i == 0 || i == MAP_WIDTH-1){
                    map -> field[i][j] = 1;
                }else if(j == 0 || j == MAP_HEIGHT-1){
                    map -> field[i][j] = 1;
                }else{
                    map -> field[i][j] = 0;
                }
            }

        }
    }else if(walls==0){
      for(i=0; i<MAP_WIDTH; i++){

            for(j=0; j<MAP_HEIGHT; j++){
                map -> field[i][j] = 0;
            }

        }
    }
    for(i=0; i<MAP_WIDTH; i++){

        for(j=0; j<MAP_HEIGHT; j++){
            printf("%d",  map -> field[i][j]);
        }
        printf("\n");
    }

    return map;
}

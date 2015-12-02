//#include <allegro.h>
//#include <stdio.h>
//
//#define SCREEN_WIDTH    640
//#define SCREEN_HEIGHT   480
//#define SCREEN_DEPTH    32
//
//#define TILE_SIZE       32
//#define TILE_COUNT      3
//#define MAP_WIDTH       20
//#define MAP_HEIGHT      20
//
//
//BITMAP* DoubleBuffer;
//BITMAP* Tiles[TILE_COUNT];
//int Map[MAP_HEIGHT][MAP_WIDTH] =
//{
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//};
//
//static const int UP = 0;
//static const int DOWN = 1;
//static const int RIGHT = 2;
//static const int LEFT = 3;
//
//typedef struct SnakeHead SnakeHead;
//typedef struct SnakeBody SnakeBody;
//
//typedef struct SnakeHead {
//    int x;
//    int y;
//    int direction;
//    int growth;
//    SnakeBody *nextElement;
//}SnakeHead;
//
//typedef struct SnakeBody {
//    int x;
//    int y;
//    SnakeBody *nextElement;
//}SnakeBody;
//
//
//
//int headMove(SnakeHead *snakeHead){
//    int direction = snakeHead -> direction;
//    if (direction == UP) {
//        snakeHead -> y--;
//    }
//    else if (direction == DOWN) {
//        snakeHead -> y++;
//    }
//    else if (direction == RIGHT) {
//        snakeHead -> x++;
//    }
//    else if (direction == LEFT) {
//        snakeHead -> x--;
//    }
//
//    if (snakeHead -> x >= MAP_HEIGHT ) {
//        snakeHead -> x = 0;
//    }
//    else if (snakeHead -> x < 0) {
//        snakeHead -> x = MAP_HEIGHT-1;
//    }
//
//    if (snakeHead -> y >= MAP_WIDTH) {
//         snakeHead -> y = 0;
//    }
//   else if (snakeHead -> y < 0) {
//        snakeHead -> y = MAP_WIDTH-1;
//    }
//    return 0;
//}
//
//int renderMap (SnakeHead *snakeHead){
//
//    clear_bitmap(DoubleBuffer);
//    int mx = snakeHead -> x;
//    int my = snakeHead -> y;
//    int requested_tile = 0;
//
//    int tile_x = mx * Tiles[requested_tile]->w;
//    int tile_y = my * Tiles[requested_tile]->h;
//
//   blit (Tiles[requested_tile],
//         DoubleBuffer,
//         0, 0,
//         tile_x, tile_y,
//         Tiles[requested_tile]->w, Tiles[requested_tile]->h);
//
//     SnakeBody *snakeBody = snakeHead -> nextElement;
//    requested_tile = 1;
//    while (snakeBody != NULL) {
//        mx = snakeBody -> x;
//        my = snakeBody -> y;
//
//        tile_x = mx * Tiles[requested_tile]->w;
//        tile_y = my * Tiles[requested_tile]->h;
//
//         blit (Tiles[requested_tile],
//         DoubleBuffer,
//         0, 0,
//         tile_x, tile_y,
//        Tiles[requested_tile]->w, Tiles[requested_tile]->h);
//        snakeBody = snakeBody -> nextElement;
//
//    }
//    showScreen();
//    return 0;
//}
//
//int showScreen ()
//{
// // blit the whole double buffer to the screen
// blit (DoubleBuffer,     // source Allegro BITMAP*
//       screen,           // destination Allegro BITMAP*
//       0, 0,             // source x,y
//       0, 0,             // destination x, y
//       DoubleBuffer->w,  // destination width
//       DoubleBuffer->h); // destination height
//
//    return 0;
//}
//
//SnakeBody *newSnakeBody (int x, int y) {
//    SnakeBody *snakeBody = malloc(sizeof(SnakeBody));
//    snakeBody -> x = x;
//    snakeBody -> y = y;
//    snakeBody ->nextElement = NULL;
//    return snakeBody;
//}
//
//int snakeMove (SnakeHead *snakeHead) {
//    int previousX = snakeHead -> x;
//    int previousY = snakeHead -> y;
//    headMove(snakeHead);
//    int newX;
//    int newY;
//    SnakeBody *snakeBody = snakeHead -> nextElement;
//    if (snakeBody == NULL) {
//        if (snakeHead -> growth > 0) {
//            snakeHead -> nextElement = newSnakeBody(previousX, previousY);
//            snakeHead -> growth--;
//        }
//    }
//
//    while (snakeBody != NULL) {
//        newX = previousX;
//        newY = previousY;
//        previousX = snakeBody -> x;
//        previousY = snakeBody -> y;
//        snakeBody -> x = newX;
//        snakeBody -> y = newY;
//        if (snakeBody -> nextElement == NULL) {
//            if (snakeHead -> growth > 0) {
//                snakeBody -> nextElement = newSnakeBody(previousX, previousY);
//                snakeHead -> growth--;
//                break;
//            }
//        }
//        snakeBody = snakeBody -> nextElement;
//    }
//    return 0;
//}
//
//SnakeHead* initialiseSnake () {
//    SnakeHead *snakeHead = malloc(sizeof(SnakeHead));
//    snakeHead -> x = 6;
//    snakeHead -> y = 1;
//    snakeHead -> direction = RIGHT;
//    snakeHead -> growth = 5;
////    SnakeBody *tmp = malloc(sizeof(SnakeBody));
////    tmp -> x = 5;
////    tmp -> y = 1;
////    SnakeBody *tmp1 = malloc(sizeof(SnakeBody));
////    tmp1 -> x = 4;
////    tmp1 -> y = 1;
////    tmp1 -> nextElement = NULL;
//    snakeHead -> nextElement = NULL;
////    tmp -> nextElement = tmp1;
////    free(tmp1);
////    free (tmp);
//    return snakeHead;
//}
//
//int main1()
//{
//    if (allegro_init() != 0)
//        return 1;
//    install_timer();
//    install_keyboard();
//    set_color_depth (SCREEN_DEPTH);
//    DoubleBuffer = create_bitmap (SCREEN_WIDTH, SCREEN_HEIGHT);
//     if (DoubleBuffer == NULL){
//        fprintf (stderr, "double buffer could not be created. program terminated\n");
//        exit(1);
//     }
//    char tile_filename[64];
//    sprintf (tile_filename, "Snake/resources/tile%d.bmp", 0);
//    Tiles[0] = load_bitmap (tile_filename, NULL);
//    sprintf (tile_filename, "Snake/resources/tile%d.bmp", 1);
//    Tiles[1] = load_bitmap (tile_filename, NULL);
//    if (Tiles[0] == NULL){
//        fprintf (stderr, "tile%d.bmp could not be loaded. program terminated\n", 0);
//        exit(1); // terminate program
//    }
//
//    set_gfx_mode (GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
//    SnakeHead *snakeHead = initialiseSnake();
//    renderMap(snakeHead);
//    while (1) {
//        int currentDirection=snakeHead->direction;
//        while (keypressed()) {
//            int lastKey = readkey();
//
//            if (lastKey >> 8 == KEY_DOWN &&currentDirection != UP) {
//                printf("You pressed down\n");
//                snakeHead -> direction = DOWN;
//            }
//            if (lastKey  >> 8 == KEY_UP && currentDirection != DOWN) {
//                snakeHead -> direction = UP;
//                printf("You pressed up\n");
//            }
//            if (lastKey  >> 8 == KEY_RIGHT && currentDirection != LEFT){
//                snakeHead -> direction = RIGHT;
//                printf("You pressed right\n");
//            }
//            if (lastKey  >> 8 == KEY_LEFT && currentDirection !=RIGHT) {
//                snakeHead -> direction = LEFT;
//                printf("You pressed left\n");
//            }
//        }
//        printf("DIRECTION = %d \n", snakeHead -> direction);
//        snakeMove(snakeHead);
//        printf ("Tête : x=%d, y=%d \n", snakeHead -> x, snakeHead -> y);
//        SnakeBody *snakeBody = snakeHead -> nextElement;
//        int i = 1;
//        while (snakeBody != NULL) {
//            printf("Part %d : x=%d , y=%d \n", i, snakeBody -> x, snakeBody -> y);
//            i++;
//            snakeBody = snakeBody -> nextElement;
//        }
//        renderMap(snakeHead);
//        rest(500);
//    }
//    return 0;
//} END_OF_MAIN() ;

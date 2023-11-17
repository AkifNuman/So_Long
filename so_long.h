
#ifndef SO_LONG
#define	SO_LONG

#include "minilibx/mlx.h"

typedef struct s_data
{
    int size_x;
    int size_y;
    void *mlx;
    void *win;
    void *image;
    void *imageidle1;
    void *imageidle2;
    void *imageidle3;
    void *image1;
    int playerplacex;
    int playerplacey;
}t_data;

int key_press();
void idle_anim();
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaltine <akifnuman@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:37:23 by akaltine          #+#    #+#             */
/*   Updated: 2023/11/18 01:09:14 by akaltine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "minilibx/mlx.h"
#include "so_long.h"
#include <stdio.h>

t_data data;
int my_key_funct(int keycode, void *param)
{
    (void) param;
    int height;
    int width = 1;
    static int tru = 0;
    height = 1;
    data.playerplacex = 1;
    data.playerplacey = 1;
    printf("3->%d\n", data.playerplacex);
    printf("4->%d\n", data.playerplacey);
    
    if (keycode == 53) // 53 is the keycode for the 'Esc' key (you can use a different keycode)
    {
        mlx_destroy_window(data.mlx, data.win);
        exit(0);
    }
    else if (tru == 0) // 32 is the keycode for the 'Space' key (you can use a different keycode)
    {
        // Load and display a new image
        mlx_clear_window(data.mlx, data.win);
        data.image1 = mlx_xpm_file_to_image(data.mlx, "luffy_walk.xpm", &data.playerplacex, &height);
        mlx_put_image_to_window(data.mlx, data.win, data.image1, data.playerplacex += 500, height);
        printf("->%d\n", width);
        printf("2->%d\n", data.playerplacex);
        tru = 1;
        printf("test1\n");
        //idle_anim(1);
    }
    else if (tru == 1)
    {
        mlx_clear_window(data.mlx, data.win);
        printf("ahmetmuhsin");
        printf("test2\n");
        data.image = mlx_xpm_file_to_image(data.mlx, "luffy.xpm", &data.playerplacex, &height);
        mlx_put_image_to_window(data.mlx, data.win, data.image, data.playerplacex += 500, height);
        printf("%d\n", width);
        tru = 0;
    }
    return (0);
}

int main(void)
{
    static int width = 1;
    static int height = 1;
    (void) width;
    (void) height;
    // MiniLibX initialization
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1920, 1080, "MiniLibX Window");

    // Load and display the initial image
    
    data.image = mlx_xpm_file_to_image(data.mlx, "LufyIdle0.xpm", &width, &height);
    mlx_put_image_to_window(data.mlx, data.win, data.image, width, height);
    
    // Hook for key press events
    mlx_key_hook(data.win, my_key_funct, data.mlx);
    // Loop to keep the window open
    mlx_loop(data.mlx);
    
    return 0;
}

void idle_anim()
{
    usleep(100);
    static int width = 1;
    static int height = 1;
        data.image = mlx_xpm_file_to_image(data.mlx, "LufyIdle0.xpm", &width, &height);
        data.imageidle1 = mlx_xpm_file_to_image(data.mlx, "LufyIdle1.xpm", &width, &height);
        data.imageidle2 = mlx_xpm_file_to_image(data.mlx, "LufyIdle2.xpm", &width, &height);
        data.imageidle3 = mlx_xpm_file_to_image(data.mlx, "LufyIdle3.xpm", &width, &height);
        
        int i = 100;
        while (i >= 0)
        {
            mlx_put_image_to_window(data.mlx, data.win, data.image, width, height);
            usleep(1000);
            //mlx_clear_window(data.mlx, data.win);

        
            mlx_put_image_to_window(data.mlx, data.win, data.imageidle1, width, height);
            usleep(1000);
            //mlx_clear_window(data.mlx, data.win);
        
        
            mlx_put_image_to_window(data.mlx, data.win, data.imageidle2, width, height);
            usleep(1000);
            //mlx_clear_window(data.mlx, data.win);
        
        
            mlx_put_image_to_window(data.mlx, data.win, data.imageidle3, width, height);
            usleep(1000);
            //mlx_clear_window(data.mlx, data.win);
            printf("asfasdfsfad");
            i--;
        }
}
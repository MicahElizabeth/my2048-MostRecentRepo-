/*********************************************
* Programmer: Micah Jenkins                  *
* Date Created: 10/09/2015                   *
* Description: My implementation of a console*
* version of the game 2048.                  *
**********************************************/

#ifndef GAME_H
#define GAME_H


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct location
{
	int row;
	int col;

} Location;

typedef struct cell
{
	Location loc;
	int value;
	int has_combined; //1 if yes 0 if no
	
}Cell;

void init_board (Cell board [][4]);
void print_board (Cell board [][4]);
void rand_gen_2_or_4 (Cell board [][4], int turn_num);
int is_board_full (Cell board[][4], int goal);
int get_move (void);
void update_board (Cell board[][4], int goal, int *score);


#endif
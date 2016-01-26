/*********************************************
* Programmer: Micah Jenkins                  *
* Date Created: 10/09/2015                   *
* Description: My implementation of a console*
* version of the game 2048.                  *
**********************************************/

#include "2048.h"

void init_board (Cell board [][4])
{
	int i = 0, j = 0;

	for (i = 0; i < 4; i ++)
	{
		for (j = 0; j < 4; j ++)
		{
			board [i][j].loc.row = i;
			board [i][j].loc.col = j;
			board [i][j].value = 0;
			board [i][j].has_combined = 0;
		}
	}
}

void print_board (Cell board [][4])
{
	int i = 0, j = 0;

	for (i = 0; i < 4; i ++)
	{
		printf("\n\n\t\t");

		for (j = 0; j < 4; j ++)
		{
			if (board [i][j].value != 0)
			{
				printf ("\t%d",
				board [i][j].value);
			}
			else
			{
				printf ("\t-");
			}
		}
		
	}

	puts("\n\n\n");
}

void rand_gen_2_or_4 (Cell board [][4], int turn_num)
{
	int i = 0, j = 0;
	//rand gen square and check if empty
	
	do
	{
		i = rand () % 4;
		j = rand () % 4;

	} while (board[i][j].value != 0);

		//rand gen 2 or 4
	if (turn_num != 0)
	{
		board[i][j].value = ((rand () % 2) + 1) * 2;
	}
	else
	{
		board[i][j].value = 2;
	}


}

//0 not full 1 full 2 if reached goal
int is_board_full (Cell board[][4], int goal)
{
	int is_full = 1;
	int i = 0, j = 0;

	for (i = 0; i < 4; i ++)
	{
		for (j = 0; j < 4; j ++)
		{
			if (board [i][j].value == 0)
			{
				is_full = 0;
				break;
			}
			else if ((board [i][j].value) == goal)
			{
				is_full = 2;
			}

		}
		
	}


	return is_full;
}

int get_move (void)
{
	char temp = '\0';
	int dir = UP;

	fflush (stdin);
	do
	{
		printf ("\tChoose a direction to shift:\n");
		printf ("\tw up\n\ts down\n\ta left\n\td right\n");
		scanf (" %c", &temp);

	} while (temp != 'w' && temp != 's' && temp != 'a' && temp != 'd');

	switch (temp)
	{
	case 'w': dir = UP;
		break;
	case 's': dir = DOWN;
		break;
	case 'a': dir = LEFT;
		break;
	case 'd': dir = RIGHT;
		break;
	default: printf ("ERROR: Invalid Direction");
		break;
	}

	return dir;
}

void update_board (Cell board[][4], int goal, int *score)
{
	int dir = UP;
	int i = 0, j = 0, k = 0;
	int flag = 0;

	do
	{
		dir = get_move ();

		switch (dir)
		{
		case UP: for (j = 0; j < 4; j ++)
				{
					for (k = 0; k < 3; k ++)
					{
					
						//collapse and move
						for (i = 0; i < 3; i ++)
						{
							if (board [i][j].value == 0 && board[i + 1][j].value != 0)
							{
								board [i][j].value += board [i + 1] [j].value;
								board [i + 1][j].value = 0;
								flag = 1;
							}
							else if (( board [i][j].has_combined != 1)&& 
									(board[i + 1][j].has_combined != 1) && 
									(board[i][j].value != 0) &&
									(board[i][j].value == board[i + 1][j].value))
							{
								board [i][j].value += board [i + 1] [j].value;
								board [i + 1][j].value = 0;
								board [i][j].has_combined = 1;
								flag = 1;
								*score += board [i][j].value;
							}
						
						}
					}
					//reset has_combined
					for (i = 0; i < 4; i ++)
					{
						board [i][j].has_combined = 0;
					}
				}

			break;

		case DOWN: for (j = 0; j < 4; j ++)
				{
					for (k = 0; k < 3; k ++)
					{
					
						//collapse and move
						for (i = 3; i >= 1; i --)
						{
							if ((board [i][j].value == 0) && (board[i - 1][j].value != 0))
							{
								board [i][j].value += board [i - 1] [j].value;
								board [i - 1][j].value = 0;
								flag = 1;
							}
							else if (( board [i][j].has_combined != 1)&& 
									(board[i - 1][j].has_combined != 1) && 
									(board[i][j].value != 0) &&
									(board[i][j].value == board[i - 1][j].value))
							{
								board [i][j].value += board [i - 1] [j].value;
								board [i - 1][j].value = 0;
								board [i][j].has_combined = 1;
								flag = 1;
								*score += board [i][j].value;
							}
						
						}
					}
					//reset has_combined
					for (i = 0; i < 4; i ++)
					{
						board [i][j].has_combined = 0;
					}
				}
			break;
		case LEFT:for (i = 0; i < 4; i ++)
				{
					for (k = 0; k < 3; k ++)
					{
					
						//collapse and move
						for (j = 0; j < 3; j ++)
						{
							if ((board [i][j].value == 0) && (board[i][j + 1].value != 0))
							{
								board [i][j].value += board [i] [j + 1].value;
								board [i][j + 1].value = 0;
								flag = 1;
							}
							else if (( board [i][j].has_combined != 1)&& 
									(board[i][j + 1].has_combined != 1) && 
									(board[i][j].value != 0) &&
									(board[i][j].value == board[i][j + 1].value))
							{
								board [i][j].value += board [i] [j + 1].value;
								board [i][j + 1].value = 0;
								board [i][j].has_combined = 1;
								flag = 1;
								*score += board [i][j].value;
							}
						
						}
					}
					//reset has_combined
					for (j = 0; j < 4; j ++)
					{
						board [i][j].has_combined = 0;
					}
				}
			break;
		case RIGHT: for (i = 0; i < 4; i ++)
				{
					for (k = 0; k < 3; k ++)
					{
					
						//collapse and move
						for (j = 3; j >= 1; j --)
						{
							if ((board [i][j].value == 0) && ( board[i][j - 1].value != 0))
							{
								board [i][j].value += board [i] [j - 1].value;
								board [i][j - 1].value = 0;
								flag = 1;
							}
							else if (( board [i][j].has_combined != 1)&& 
									(board[i][j - 1].has_combined != 1) && 
									(board[i][j].value != 0) &&
									(board[i][j].value == board[i][j - 1].value))
							{
								board [i][j].value += board [i] [j - 1].value;
								board [i][j - 1].value = 0;
								board [i][j].has_combined = 1;
								flag = 1;
								*score += board [i][j].value;
							}
						
						}
					}
					//reset has_combined
					for (j = 0; j < 4; j ++)
					{
						board [i][j].has_combined = 0;
					}
				}
			break;

		default: break;
		}

	} while (flag == 0 && is_board_full (board, goal) == 0);

}


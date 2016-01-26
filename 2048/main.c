#include "2048.h"

int main (void)
{
	Cell board [4][4];
	int turn_number = 0;
	int goal = 2048, score = 0;

	srand ((unsigned int) time (NULL));

	init_board (board);
	do
	{
		system ("cls");
		rand_gen_2_or_4 (board, turn_number);
		printf ("\n\tScore: %d\n", score);
		print_board (board);
		update_board (board, goal, &score);
		
		turn_number ++;
		if (is_board_full (board, goal) == 2)
		{
			system ("cls");
			print_board (board);

			printf ("\t\tYou've reached %d!!!\n\t\tTry to get %d\n\n", goal, goal * 2);
			goal *= 2;
			system ("pause");
		}

	} while (is_board_full (board, goal) != 1);

	system ("Cls");
	printf ("\tGame Over\n");
	printf ("\tScore: %d\n", score);
	print_board (board);



	return 0;
}
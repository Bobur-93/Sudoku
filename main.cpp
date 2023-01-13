# include "sudoku.h"



int main()
{
	int matr_sud[81], diff;

	srand(time(NULL));

	diff = rand()%3;
	//printf("%d\n", diff);

	filling_sudoku(matr_sud);
	mashing_sudoku (matr_sud, diff);

	


	getchar();

	return 0;
}
# include "sudoku.h"


	//Здесь будем удалять клетки матрицы и проверять на решаемость нашу матрицу
//

int mashing_sudoku (int* matr_sud, int diff)
{
	//Здесь удаляем случайно клетки матрицы 
	int i, j, n;
	int buff[81];

	srand(time(NULL));

	//Здесь получаем процент затирания матрицы т.е. сложность
	switch (diff)
	{
		case 0:
			n=43;
			break;
		case 1:
			n=37;
			break;
		case 2:
			n=30;
			break;
	}


	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
		{
			buff[i * 9 + j] = matr_sud[i * 9 + j];
		}
		

	}

	for (i=0; i<9; i++)
	{		
		for (j=0; j<9; j++)
		{
			if ((rand()%100)>n)
				buff[i*9+j] = 0;
			//printf("%d ", buff[i*9+j]);
		}
		//printf("\n");
		
	}

	solver(buff);


	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
		{
			printf("%d ", buff[i*9+j]);
		}
		printf("\n");

	}







	return 0;
}
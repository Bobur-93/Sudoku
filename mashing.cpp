# include "sudoku.h"


	//����� ����� ������� ������ ������� � ��������� �� ���������� ���� �������
//

int mashing_sudoku (int* matr_sud, int diff)
{
	//����� ������� �������� ������ ������� 
	int i, j, n;
	int buff[81];

	srand(time(NULL));

	//����� �������� ������� ��������� ������� �.�. ���������
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
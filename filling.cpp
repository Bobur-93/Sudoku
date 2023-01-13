# include "sudoku.h"

// В этом файле я заполняю матрицу 9 на 9

int Array(int* Array)
{
	//Эта функция заполняет массив размера 9 числами от 1 до 9
	int i;

	for (i=0; i<9; i++)
	{
		Array[i]=i+1;
	}

	return 0;
}

int filling (int* matr_sud, int* mass)
{
	//Эта функция заполняет матрицу 9 на 9 следующим образом:
	/* 123456789
	   456789123
	   789123456
	   234567891
	   567891234
	   891234567
	   345678912
	   678912345
	   912345678

	*/

	int i, j, n;

	n=1;
	for (i=0; i<9; i++)
	{
		if (i<3)
		{
			for (j=0; j<9; j++)
			{
				matr_sud[i*9+j] = mass[(i*3+j)%9];
		//		printf("%d ", matr_sud[i*9+j]);
			}
		//	printf("\n");
		}
		else
		{
			for (j=0; j<9; j++)
			{
				matr_sud[i*9+j] = mass[(i*3+j+n)%9];
			//	printf("%d ", matr_sud[i*9+j]);
			}
			if (i==5)
				n++;
			//printf("\n");
		}
	}


	return 0;
}

int transponir_matr(int* matr_sud)
{
	// Транспонируем матрицу
	int i, j, t;

	for ( int i = 1; i < 9; i++ )
	{
		for ( int j = 0; j < 8; j++ )
		{
			t = matr_sud[i*9+j]; 
			matr_sud[i*9+j] = matr_sud[j*9+i]; 
			matr_sud[j*9+i] = t ; 
		}
	}

	return 0;
}

int lines_matr(int* matr_sud)
{
	// Меняем местами строки матрицы
	int i, j, a, b, buff;

	i = rand()%3;
	a = rand()%3;
	b = rand()%3;
	if (a==b)
	b = (b+1)%3;
	
	for (j=0; j<9; j++)
	{
		buff = matr_sud[(i*3+a)*9+j];
		matr_sud[(i*3+a)*9+j] = matr_sud[(i*3+b)*9+j];
		matr_sud[(i*3+b)*9+j] = buff;
	}

	return 0;
}

int columns_matr (int* matr_sud)
{
	//Меняем местами столбцы матрицы
	int i, j, a, b, buff;

	i = rand()%3;
	a = rand()%3;
	b = rand()%3;
	if (a==b)
	b = (b+1)%3;
	
	for (j=0; j<9; j++)
	{
		buff = matr_sud[j*9+(i*3+a)];
		matr_sud[j*9+(i*3+a)] = matr_sud[j*9+(i*3+b)];
		matr_sud[j*9+(i*3+b)] = buff;
	}

	return 0;
}

int vertical_exchange (int* matr_sud)
{
	//Меняем местами вертикальные блоки (В блок входит 3 подряд идущие строки)
	int i, j, a, b, buff;

	a = rand()%3;
	b = rand()%3;
	if (a==b)
		b = (b+1)%3;

	for (i=0; i<3; i++)
	{
		for (j=0; j<9; j++)
		{
			buff = matr_sud[(a*3+i)*9+j];
			matr_sud[(a*3+i)*9+j] = matr_sud[(b*3+i)*9+j];
			matr_sud[(b*3+i)*9+j] = buff;
		}
	}

	return 0;
}

int horizontal_exchange(int* matr_sud)
{
	//Меняем местами горизонтальные блоки
	int i, j, a, b, buff;

	a = rand()%3;
	b = rand()%3;
	if (a==b)
		b = (b+1)%3;

	for (i=0; i<9; i++)
	{
		for (j=0; j<3; j++)
		{
			buff = matr_sud[i*9+(a*3+j)];
			matr_sud[i*9+(a*3+j)] = matr_sud[i*9+(b*3+j)];
			matr_sud[i*9+(b*3+j)] = buff;
		}
	}

	return 0;
}

int mix_matr (int* matr_sud)
{
	//Размещиваем нащу матрицу
	int i, iter, num_func;

	iter = rand()%100+5;

	/*if (rand()%2)
		transponir_matr(matr_sud);*/

	for (i=0; i<iter; i++)
	{
		num_func = rand()%4;
		switch (num_func)
		{
		case 0:
			horizontal_exchange(matr_sud);
			break;
		case 1:
			lines_matr(matr_sud);
			break;
		case 2:
			columns_matr(matr_sud);
			break;
		case 3:
			vertical_exchange(matr_sud);
			break;		
		}
	}

	return 0;
}
int filling_sudoku(int* matr_sud)
{
	//Получам готовую матрицу с которой будем работать
	int i, j;
	int *mass = new int[9];

	srand(time(NULL));

	Array(mass);

	filling(matr_sud,mass);

	mix_matr(matr_sud);
		
	/*for (i=0; i<9; i++)
	{		
		for (j=0; j<9; j++)
		{
			printf("%d ", matr_sud[i*9+j]);
		}
		printf("\n");
		
	}*/


	return 0;
}
# include "sudoku.h"

class Matrix_list
{
private:
	static int row_col[9];
	static int row_quad[9][3];
	static int col_row[9];
	static int col_quad[9][3];
	int j;

public:

	void delete_row(int a);
	
	void rollback_row(int a);

	void delete_col(int a);

	void rollback_col(int a);
	
	void delete_quad(int a);

	void rollback_quad(int a);
	
	void reset();

	void print_matr();

	void filling_the_table(int* buff, int* knut_tab, int* row_and_col, int size_tab);
	
	Matrix_list();
	~Matrix_list();

};
void Matrix_list::delete_row(int a)
{
	for (int i = 0; i < 9; i++)
	{
		col_row[a] = -1;
	}
}
void Matrix_list::delete_col(int a)
{
	for (int i = 0; i < 9; i++)
	{
		row_col[a] = -1;
	}
}
void Matrix_list::delete_quad(int a)
{
	for (int i = 0; i < 3; i++)
	{
		switch (a)
		{
		case 0:
			for (int i = 0; i < 3; i++)
			{
				row_quad[i][0] = 0;
			}
			for (int i = 0; i < 3; i++)
			{
				col_quad[i][0] = 0;
			}
			break;
		case 1:
			for (int i = 0; i < 3; i++)
			{
				row_quad[i][1] = 1;
			}
			for (int i = 3; i < 6; i++)
			{
				col_quad[i][0] = 1;
			}
			break;
		case 2:
			for (int i = 0; i < 3; i++)
			{
				row_quad[i][2] = 2;
			}
			for (int i = 6; i < 9; i++)
			{
				col_quad[i][0] = 2;
			}
			break;
		case 3:
			for (int i = 3; i < 6; i++)
			{
				row_quad[i][0] = 3;
			}
			for (int i = 0; i < 3; i++)
			{
				col_quad[i][1] = 3;
			}
			break;
		case 4:
			for (int i = 3; i < 6; i++)
			{
				row_quad[i][1] = 4;
			}
			for (int i = 3; i < 6; i++)
			{
				col_quad[i][1] = 4;
			}
			break;
		case 5:
			for (int i = 3; i < 6; i++)
			{
				row_quad[i][2] = 5;
			}
			for (int i = 6; i < 9; i++)
			{
				col_quad[i][1] = 5;
			}
			break;
		case 6:
			for (int i = 6; i < 9; i++)
			{
				row_quad[i][0] = 6;
			}
			for (int i = 0; i < 3; i++)
			{
				col_quad[i][2] = 6;
			}
			break;
		case 7:
			for (int i = 6; i < 9; i++)
			{
				row_quad[i][1] = 7;
			}
			for (int i = 3; i < 6; i++)
			{
				col_quad[i][2] = 7;
			}
			break;
		case 8:
			for (int i = 6; i < 9; i++)
			{
				row_quad[i][2] = 8;
			}
			for (int i = 6; i < 9; i++)
			{
				col_quad[i][2] = 8;
			}
			break;
		}

	}
}
void Matrix_list::rollback_row(int a)
{
	for (int i = 0; i < 9; i++)
	{
		col_row[a] = a;
	}
}
void Matrix_list::rollback_col(int a)
{
	for (int i = 0; i < 9; i++)
	{
		row_col[a] = a;
	}
}
void Matrix_list::rollback_quad(int a)
{
	for (int i = 0; i < 3; i++)
	{
		switch (a)
		{
		case 0:
			for (int i = 0; i < 3; i++)
			{
				row_quad[i][0] = -1;
			}
			for (int i = 0; i < 3; i++)
			{
				col_quad[i][0] = -1;
			}
			break;
		case 1:
			for (int i = 0; i < 3; i++)
			{
				row_quad[i][1] = -1;
			}
			for (int i = 3; i < 6; i++)
			{
				col_quad[i][0] = -1;
			}
			break;
		case 2:
			for (int i = 0; i < 3; i++)
			{
				row_quad[i][2] = -1;
			}
			for (int i = 6; i < 9; i++)
			{
				col_quad[i][0] = -1;
			}
			break;
		case 3:
			for (int i = 3; i < 6; i++)
			{
				row_quad[i][0] = -1;
			}
			for (int i = 0; i < 3; i++)
			{
				col_quad[i][1] = -1;
			}
			break;
		case 4:
			for (int i = 3; i < 6; i++)
			{
				row_quad[i][1] = -1;
			}
			for (int i = 3; i < 6; i++)
			{
				col_quad[i][1] = -1;
			}
			break;
		case 5:
			for (int i = 3; i < 6; i++)
			{
				row_quad[i][2] = -1;
			}
			for (int i = 6; i < 9; i++)
			{
				col_quad[i][1] = -1;
			}
			break;
		case 6:
			for (int i = 6; i < 9; i++)
			{
				row_quad[i][0] = -1;
			}
			for (int i = 0; i < 3; i++)
			{
				col_quad[i][2] = -1;
			}
			break;
		case 7:
			for (int i = 6; i < 9; i++)
			{
				row_quad[i][1] = -1;
			}
			for (int i = 3; i < 6; i++)
			{
				col_quad[i][2] = -1;
			}
			break;
		case 8:
			for (int i = 6; i < 9; i++)
			{
				row_quad[i][2] = -1;
			}
			for (int i = 6; i < 9; i++)
			{
				col_quad[i][2] = -1;
			}
			break;
		}
	}	
}
void Matrix_list::reset()
{
	for (int i = 0; i < 9; i++)
	{
		rollback_row(i);
		rollback_col(i);
	}	
	for (int i = 0; i < 9; i++)
	{
		rollback_quad(i);
	}
}
void Matrix_list::print_matr()
{
	for (int i = 0; i < 9; i++)
	{
		cout << row_col[i] << ' ';		
	}
	cout << '\n';
	cout << '\n';
	for (int i = 0; i < 9; i++)
	{
		cout << col_row[i] << ' ';
	}
	cout << '\n';
	cout << '\n';
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << row_quad[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << col_quad[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';
}
void Matrix_list::filling_the_table(int* buff, int* knut_tab, int* row_and_col, int size_tab)
{
	int row, column, t = 0, flag, h = 0;

	for (int i = 0; i < 9; i++)
	{
		if (col_row[i] != -1)
		{
			row_and_col[h] = col_row[i];
			h++;
		}
		if (row_col[i] != -1)
		{
			row_and_col[size_tab + t] = row_col[i];
			t++;
		}
	}
	t = 0;
	/*for (int i = 0; i < 2*size_tab; i++)
	{
		if (i==size_tab)
		{
			cout << '\n';
		}
		cout << row_and_col[i] << ' ';
	}*/
	cout << '\n';
	for (int i = 0; i < size_tab; i++)
	{
		row = row_and_col[i];
		for (int j = 0; j < size_tab; j++)
		{
			column = row_and_col[size_tab + j];
			if (buff[row * 9 + column] != 0)
			{
				knut_tab[t] = 1;
				t++;
			}
			else
			{
				flag = 0;
				for (int k = 0; k < 3; k++)
				{
					for (h = 0; h < 3; h++)
					{
						if (row_quad[row][k] == col_quad[column][h] && row_quad[row][k] != -1)
						{
							flag = 1;
							break;							
						}
					}
					if (flag == 1)
					{
						break;
					}
				}
				if (flag == 0)
				{
					knut_tab[t] = 0;
					t++;
				}
				else
				{
					knut_tab[t] = 1;
					t++;
				}
			}
		}		
	}
	//getchar();
}


Matrix_list::Matrix_list()
{
}

Matrix_list::~Matrix_list()
{
}

int Matrix_list::row_col[9];
int Matrix_list::col_row[9];
int Matrix_list::col_quad[9][3];
int Matrix_list::row_quad[9][3];


class List_of_numbers
{
private:
	static int number_array[3][9];

public:
	static int quantity;

	void add_row(int a)
	{
		number_array[0][quantity] = a;
	}
	void add_col(int a)
	{
		number_array[1][quantity] = a;
	}
	void add_quad(int a)
	{
		number_array[2][quantity] = a;
	}
	void delete_row()
	{
		number_array[0][quantity] = -1;
	}
	void delete_col()
	{
		number_array[1][quantity] = -1;
	}
	void delete_quad()
	{
		number_array[2][quantity] = -1;
	}
	void reset();

	void print_matr();

	void copy(int* cop_arr)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cop_arr[i * 9 + j] = number_array[i][j];
			}
		}
	}
	
	List_of_numbers();
	~List_of_numbers();


};

List_of_numbers::List_of_numbers()
{
}

List_of_numbers::~List_of_numbers()
{
}
void List_of_numbers::reset()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			number_array[i][j] = -1;
		}
	}
	quantity = 0;
}

void List_of_numbers::print_matr()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << number_array[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << quantity;
	cout << '\n';
	cout << '\n';
}

int List_of_numbers::number_array[3][9];
int List_of_numbers::quantity;

void counting_numbers(int* buff, int* count_num)
{
	int i, j, n;
	
	for ( i = 0; i < 9; i++)
	{
		count_num[i] = 0;
	}

	for (i = 1; i < 10; i++)
	{
		for (j = 0; j < 9; j++)
		{
			for ( n = 0; n < 9; n++)
			{
				if (i == buff[j * 9 + n])
				{
					count_num[i-1] = count_num[i-1] + 1;
				}
			}
		}
	}
	
}

void counting_the_maximum(int* count_num, int* index)
{
	int i, max = 0;

	*index = 0;
	for (i = 0; i < 9; i++)
	{
		if (max < count_num[i])
		{
			max = count_num[i];
			*index = i;
		}
	}
}

void drawing_up_a_table(int* buff, int current_num)
{
	int i, j;
	Matrix_list m_list;
	List_of_numbers list_num;

	m_list.reset();
	list_num.reset();

	
	for ( i = 0; i < 9; i++)
	{
		for ( j = 0; j < 9; j++)
		{
			if (buff[i*9+j] == current_num)
			{				
				m_list.delete_row(i);
				m_list.delete_col(j);
				list_num.add_row(i);
				list_num.add_col(j);
				
				if (i<3)
				{
					if (j<3)
					{						
						m_list.delete_quad(0);
						list_num.add_quad(0);
					}
					else
					{
						if (3 <= j && j < 6)
						{							
							m_list.delete_quad(1);
							list_num.add_quad(1);
						}
						else
						{							
							m_list.delete_quad(2);
							list_num.add_quad(2);
						}
					}
				}
				else
				{
					if (3 <= i && i < 6)
					{
						if (j<3)
						{							
							m_list.delete_quad(3);
							list_num.add_quad(3);
						}
						else
						{
							if (3 <= j && j < 6)
							{								
								m_list.delete_quad(4);
								list_num.add_quad(4);
							}
							else
							{								
								m_list.delete_quad(5);
								list_num.add_quad(5);
							}
						}
					}
					else
					{
						if (j<3)
						{
							m_list.delete_quad(6);
							list_num.add_quad(6);
						}
						else
						{
							if (3 <= j && j < 6)
							{
								m_list.delete_quad(7);
								list_num.add_quad(7);
							}
							else
							{
								m_list.delete_quad(8);
								list_num.add_quad(8);
							}
						}
					}
				}				
				list_num.quantity++;
			}
		}
	}

	//list_num.print_matr();
	//m_list.print_matr();
}

int knut_alg_x(int* buff, int current_num)
{
	Matrix_list m_list;
	List_of_numbers list_num;

	int size_tab, i, j, max, max_col, pos_r, pos_c, flag_1, flag_2, x = 0;
	int *knut_tab = NULL,  *number_of_zeros = NULL;
	int *row_and_col = NULL;

	size_tab = 9 - list_num.quantity;

	if (size_tab <= 0)
	{
		return 0;
	}

	knut_tab = (int*) malloc (sizeof(int) * size_tab*size_tab);
	
	row_and_col = (int*)malloc(sizeof(int) * 2 * size_tab); //new int*[2];
	
	number_of_zeros = (int*)malloc(sizeof(int) * size_tab);//new int[size_tab];
	

	//m_list.print_matr();

	m_list.filling_the_table(buff, knut_tab, row_and_col, size_tab);
	/*for (i = 0; i < size_tab*size_tab; i++)
	{
		if (i % size_tab  == 0 && i != 0)
		{
			cout << '\n';
		}
		cout << knut_tab[i] << ' ';		
	}
	cout << '\n';

	cout << "row_and_col:\n";
	for (i = 0; i < 2*size_tab; i++)
	{
		if (i % size_tab == 0 && i != 0)
		{
			cout << '\n';
		}
		cout << row_and_col[i] << ' ';
	}
	cout << '\n';*/

	

	flag_1 = 0;
	for ( i = 0; i < size_tab*size_tab; i++)
	{
		if (knut_tab[i] == 0)
		{
			flag_1 = 1;
			break;
		}
	}
	if (flag_1 == 0)
	{
		free(knut_tab);
		knut_tab = NULL;		
		free(row_and_col);
		row_and_col = NULL;
		free(number_of_zeros);
		number_of_zeros = NULL;
		return 1;
	}
	
	
	pos_c = 0;
	for ( i = 0; i < size_tab; i++)
	{
		max_col = 0;
		for ( j = 0; j < size_tab; j++)
		{
			if (knut_tab[j*size_tab + i] == 1)
			{
				max_col++;
			}
		}
		number_of_zeros[i] = max_col;		
	}

	/*cout << "number_of_zeros:\n";
	for (i = 0; i < size_tab; i++)
	{
		if (i % size_tab == 0 && i != 0)
		{
			cout << '\n';
		}
		cout << number_of_zeros[i] << ' ';
	}
	cout << '\n';*/

	for ( j = 0; j < size_tab; j++)
	{
		max = 0;
		flag_2 = 0;
		for (i = 0; i < size_tab; i++)
		{
			if (max < number_of_zeros[i])
			{
				max = number_of_zeros[i];
				pos_c = i;
			}
		}
		if (max == size_tab && size_tab != 1)
		{
			free(knut_tab);
			knut_tab = NULL;
			free(row_and_col);
			row_and_col = NULL;
			free(number_of_zeros);
			number_of_zeros = NULL;
			return 1;
		}
		for (i = 0; i < size_tab; i++)
		{
			if (knut_tab[i*size_tab + pos_c] == 0)
			{
				pos_r = i;
				break;
			}
		}

		m_list.delete_row(row_and_col[pos_r]);
		m_list.delete_col(row_and_col[size_tab + pos_c]);
		list_num.add_row(row_and_col[pos_r]);
		list_num.add_col(row_and_col[size_tab + pos_c]);
		if (row_and_col[pos_r]<3)
		{
			if (row_and_col[size_tab + pos_c] < 3)
			{
				m_list.delete_quad(0);
				list_num.add_quad(0);
			}
			else
			{
				if (3 <= row_and_col[size_tab + pos_c] && row_and_col[size_tab + pos_c] < 6)
				{
					m_list.delete_quad(1);
					list_num.add_quad(1);
				}
				else
				{
					m_list.delete_quad(2);
					list_num.add_quad(2);
				}
			}
		}
		else
		{
			if (3 <= row_and_col[pos_r] && row_and_col[pos_r] < 6)
			{
				if (row_and_col[size_tab + pos_c] < 3)
				{
					m_list.delete_quad(3);
					list_num.add_quad(3);
				}
				else
				{
					if (3 <= row_and_col[size_tab + pos_c] && row_and_col[size_tab + pos_c] < 6)
					{
						m_list.delete_quad(4);
						list_num.add_quad(4);
					}
					else
					{
						m_list.delete_quad(5);
						list_num.add_quad(5);
					}
				}
			}
			else
			{
				if (row_and_col[size_tab + pos_c] < 3)
				{
					m_list.delete_quad(6);
					list_num.add_quad(6);
				}
				else
				{
					if (3 <= row_and_col[size_tab + pos_c] && row_and_col[size_tab + pos_c] < 6)
					{
						m_list.delete_quad(7);
						list_num.add_quad(7);
					}
					else
					{
						m_list.delete_quad(8);
						list_num.add_quad(8);
					}
				}
			}
		}
		list_num.quantity++;

		if (list_num.quantity == 9)
		{
			free(knut_tab);
			knut_tab = NULL;
			free(row_and_col);
			row_and_col = NULL;
			free(number_of_zeros);
			number_of_zeros = NULL;
			return 0;
		}
		else
		{
			x = knut_alg_x(buff, current_num);
			if (x == 1)
			{
				flag_2 = 1;
				m_list.rollback_row(row_and_col[pos_r]);
				m_list.rollback_col(row_and_col[size_tab + pos_c]);
				list_num.quantity--;
				list_num.delete_row();
				list_num.delete_col();
				list_num.delete_quad();
				number_of_zeros[pos_c] = 0;
			}
			else
			{
				free(knut_tab);
				knut_tab = NULL;
				free(row_and_col);
				row_and_col = NULL;
				free(number_of_zeros);
				number_of_zeros = NULL;
				return 0;
			}
		}

	}

	if (flag_2 == 1)
	{
		return 1;
	}
	/*cout << size_tab << '\n';
	for ( i = 0; i < size_tab*size_tab; i++)
	{
		cout << knut_tab[i] << ' ';
		if ((i%size_tab)==0)
		{
			cout << '\n';
		}
	}
	cout << '\n';*/


	//list_num.print_matr();
	//m_list.print_matr();

	//for ( i = 0; i < size_tab; i++)
	//{
	//	delete[] knut_tab[i];
	//}
	/*delete[] knut_tab;
	for (i = 0; i < 2; i++)
	{
		delete[] row_and_col[i];
	}
	delete[] row_and_col;
	delete[] number_of_zeros;*/
}

void aggregation(int* buff, int current_num)
{
	int cop_arr[18], n, m;
	List_of_numbers list_num;
	
	//list_num.print_matr();

	list_num.copy(cop_arr);

	/*for (int i = 0; i < 18; i++)
	{
		cout << cop_arr[i] << ' ';
	}
	cout << '\n';*/

	for (int i = 0; i < 9; i++)
	{
		n = cop_arr[i];
		m = cop_arr[9 + i];
		if (n != -1 || m != -1)
		{
			buff[n * 9 + m] = current_num;
		}
		else
		{
			break;
		}		
	}
}

int solver(int* buff)
{
	int i, current_num;
	int count_num[9];
	

	counting_numbers(buff, count_num);

	for ( i = 0; i < 9; i++)
	{
		cout << count_num[i] << ' ';
	}
	cout << '\n';

			
	for ( i = 0; i < 9; i++)
	{
		counting_the_maximum(count_num, &current_num);
		current_num = current_num + 1;
		drawing_up_a_table(buff, current_num);
		knut_alg_x(buff, current_num);
		aggregation(buff, current_num);
		count_num[current_num-1] = 0;
		cout << current_num << '\n';
	}
	
	for ( i = 0; i < 9; i++)
	{
		cout << count_num[i] << ' ';
	}

	cout << '\n';
	cout << '\n';

	return 0;
}
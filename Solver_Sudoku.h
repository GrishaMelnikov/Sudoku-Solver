#pragma once

#define size_line_3d_array 3
#define size_column_3d_array 3
#define size_figure_3d_array 9
#define size_line_2d_array 9
#define size_column_2d_array 9

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<Windows.h>
#include<stdlib.h>

using namespace std;
using vector_2d = vector<vector<char>>;

vector <char> missing_numbers_cube;
vector <char> missing_numbers_line;
vector <char> missing_numbers_column;
vector <int> coordinates_possible_position;


void zeroint_empty_cases(char(*arr_2d)[size_column_2d_array], char(*arr_3d)[size_line_3d_array][size_column_3d_array], string(*status_cases)[size_column_2d_array]);
void find_missing_numbers_cube(char(*cube)[size_column_3d_array], string(*status_cubes)[size_column_2d_array], char* numbers, int index_figure, int size_line, int size_column);
void find_missing_numbers_line(char* arr, string(*status_cubes)[size_column_2d_array], char* numbers, int index_line);
void find_missing_numbers_column(char(*arr)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], char* numbers, int index_column);
int value_possible_positions_number_in_the_cube(char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_figure, char number);
int value_possible_positions_number_in_the_line(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_line, char number);
int value_possible_positions_number_in_the_line(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_line, char number);
int value_possible_positions_number_in_the_column(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_column, char number);
void cycle_for_cube(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int(*data_previous_values_case)[size_column_2d_array], bool& status, char* numbers);
int value_of_permutations(int value_empty_case);
int value_missing_number_in_the_line(char* (arr_2d)[size_column_2d_array], char* numbers, string(*status_cubes)[size_column_2d_array], int index_line);
void all_combinations_line(vector_2d& array_all_combinations_line);
bool check_on_unique_combination(vector_2d array_combinations, vector<char> combination, int value_missing_numbers);
bool verify_on_solution(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], char* numbers);
void paste_combination_in_sudoku(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_line);
void zeroint_empty_cases(char(*arr_2d)[size_column_2d_array], char(*arr_3d)[size_line_3d_array][size_column_3d_array], string(*status_cases)[size_column_2d_array]);
void print_array(vector<vector<char> > vector, int index_line_arr, int index_column_arr);
void print_array(vector <char> arr);
void print_array(char(*array)[size_column_2d_array], int size_line, int size_column);
bool Exist_number_in_the_line(char* arr, string(*status_cube)[size_column_2d_array], int size_column, int index_line, char number);
bool Exist_number_in_the_column(char(*arr)[size_column_2d_array], string(*status_cube)[size_column_2d_array], int size_line, int index_column, char number);
bool Exist_number_cube(char(*arr)[size_column_3d_array], string(*status_cases)[size_column_2d_array], int index_figure, int size_line, int size_column, char number);
void default_settings(string(*status_case)[size_column_2d_array], int size_line, int size_column);
void set_parametr(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*array)[size_column_2d_array], string(*arr_status)[size_column_2d_array], int index_figure, int line, int column, char number, string status);
int char_to_int(char symbol);
int factorial(int number);
void swap_numbers(vector<char>& arr, int index_number_1, int index_number_2);
void copy_vector(vector<char> arr_1, vector<char>& arr_2);



void find_missing_numbers_cube(char(*cube)[size_column_3d_array], string(*status_cubes)[size_column_2d_array], char* numbers, int index_figure, int size_line, int size_column)
{
	missing_numbers_cube.resize(0);

	for (int index_numbers = 0; index_numbers < size_figure_3d_array; index_numbers++)
	{
		if (!Exist_number_cube(cube, status_cubes, index_figure, size_line, size_column, numbers[index_numbers]))
		{
			missing_numbers_cube.push_back(numbers[index_numbers]);
		}
	}
}

void find_missing_numbers_line(char* arr, string(*status_cubes)[size_column_2d_array], char* numbers, int index_line)
{
	missing_numbers_line.resize(0);

	for (int index_numbers = 0; index_numbers < size_column_2d_array; index_numbers++)
	{
		if (!Exist_number_in_the_line(arr, status_cubes, size_column_2d_array, index_line, numbers[index_numbers]))
		{
			missing_numbers_line.push_back(numbers[index_numbers]);
		}
	}
}

void find_missing_numbers_column(char(*arr)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], char* numbers, int index_column)
{
	missing_numbers_column.resize(0);

	for (int index_numbers = 0; index_numbers < size_line_2d_array; index_numbers++)
	{
		if (!Exist_number_in_the_column(arr, status_cubes, size_line_2d_array, index_column, numbers[index_numbers]))
		{
			missing_numbers_column.push_back(numbers[index_numbers]);
		}
	}
}

int value_possible_positions_number_in_the_cube(char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_figure, char number)
{
	int value_possible_positions = 0;

	coordinates_possible_position.resize(0);

	for (int index_line = 0; index_line < size_line_3d_array; index_line++)
	{
		for (int index_column = 0; index_column < size_column_3d_array; index_column++)
		{
			if (status_cubes[((index_figure / size_line_3d_array) * size_line_3d_array) + index_line][((index_figure % size_column_3d_array) * size_column_3d_array) + index_column] == "free")
			{
				if (!Exist_number_in_the_line(arr_2d[((index_figure / size_line_3d_array) * size_line_3d_array) + index_line], status_cubes, size_column_2d_array, ((index_figure / size_column_3d_array) * size_column_3d_array) + index_line, number) && !Exist_number_in_the_column(arr_2d, status_cubes, size_line_2d_array, (index_figure % size_column_3d_array) * size_column_3d_array + index_column, number))
				{
					coordinates_possible_position.push_back(index_line);
					coordinates_possible_position.push_back(index_column);
					value_possible_positions++;
				}
			}
		}
	}

	return value_possible_positions;
}

int value_possible_positions_number_in_the_line(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_line, char number)
{
	int value_possible_positions = 0;

	coordinates_possible_position.resize(0);

	for (int index_column = 0; index_column < size_column_2d_array; index_column++)
	{
		int index_figure = ((index_line / size_line_3d_array) * size_line_3d_array) + (index_column / size_column_3d_array);

		if (status_cubes[index_line][index_column] != "busy")
		{
			if (!Exist_number_in_the_column(arr_2d, status_cubes, size_line_2d_array, index_column, number) && !Exist_number_cube(arr_3d[index_figure], status_cubes, index_figure, size_line_3d_array, size_column_3d_array, number))
			{
				coordinates_possible_position.push_back(index_line);
				coordinates_possible_position.push_back(index_column);
				value_possible_positions++;
			}
		}
	}

	return value_possible_positions;
}

int value_possible_positions_number_in_the_column(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_column, char number)
{
	int value_possible_positions = 0;

	coordinates_possible_position.resize(0);

	for (int index_line = 0; index_line < size_line_2d_array; index_line++)
	{
		int index_figure = ((index_line / size_line_3d_array) * size_line_3d_array) + (index_column / size_column_3d_array);

		if (status_cubes[index_line][index_column] == "free")
		{
			if (!Exist_number_in_the_line(arr_2d[index_line], status_cubes, size_column_2d_array, index_line, number) && !Exist_number_cube(arr_3d[index_figure], status_cubes, index_figure, size_line_3d_array, size_column_3d_array, number))
			{
				coordinates_possible_position.push_back(index_line);
				coordinates_possible_position.push_back(index_column);
				value_possible_positions++;
			}
		}
	}

	return value_possible_positions;
}

void cycle_for_cube(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int(*data_previous_values_case)[size_column_2d_array], bool& status, char* numbers)
{
	bool exist_unique_number = false;

	for (int index_figure = 0; index_figure < size_figure_3d_array; index_figure++)
	{
		find_missing_numbers_cube(arr_3d[index_figure], status_cubes, numbers, index_figure, size_line_3d_array, size_column_3d_array);
		int index_missing_number = 0;

		for (int index_line = 0; index_line < size_line_3d_array; index_line++)
		{
			for (int index_column = 0; index_column < size_column_3d_array; index_column++)
			{
				int line_2d_array = (index_figure / size_line_3d_array) * size_line_3d_array + index_line;
				int column_2d_array = (index_figure % size_column_3d_array) * size_column_3d_array + index_column;

				if (status_cubes[line_2d_array][column_2d_array] == "free")
				{
					int value_possible_positions = value_possible_positions_number_in_the_cube(arr_2d, status_cubes, index_figure, missing_numbers_cube[index_missing_number]);

					if (value_possible_positions == 1)
					{
						set_parametr(arr_3d, arr_2d, status_cubes, index_figure, coordinates_possible_position[0], coordinates_possible_position[1], missing_numbers_cube[index_missing_number], "busy");
						exist_unique_number = true;
					}
					index_missing_number++;
				}
			}
		}
	}

	status = exist_unique_number;

}

int value_of_permutations(int value_empty_case)
{
	return factorial(value_empty_case);
}

void zeroing_the_array(int(*data_previous_values_case)[10], string(*status_cubes)[size_column_2d_array], int line)
{
	for (int index_column = 0; index_column < size_column_2d_array; index_column++)
	{
		if (status_cubes[line][index_column] == "free")
		{
			int index_case = (line * 3) + index_column;

			for (int index_array_previous_values_case = 0; index_array_previous_values_case < 10; index_array_previous_values_case++)
			{
				data_previous_values_case[index_case][index_array_previous_values_case] = 0;
			}
		}
	}
}

int value_missing_number_in_the_line(char* (arr_2d)[size_column_2d_array], char* numbers, string(*status_cubes)[size_column_2d_array], int index_line)
{
	find_missing_numbers_line(arr_2d[index_line], status_cubes, numbers, index_line);

	return missing_numbers_line.size();
}

void all_combinations_line(vector_2d& array_all_combinations_line)
{
	vector<char> extra_array;

	int value_missing_numbers = missing_numbers_line.size();

	int index_line_array_all_combinations = 0;

	for (int index = 0; index < factorial(value_missing_numbers); index++)
	{
		bool combination_does_not_find = true;

		int index_number_array_missing_numbers = 0;

		while (combination_does_not_find && index_number_array_missing_numbers != 5)
		{
			for (int index_array = 0; index_array < value_missing_numbers; index_array++)
			{
				extra_array.resize(0);

				copy_vector(missing_numbers_line, extra_array);

				swap_numbers(extra_array, index_number_array_missing_numbers, index_array);

				if (check_on_unique_combination(array_all_combinations_line, extra_array, value_missing_numbers))
				{
					swap_numbers(missing_numbers_line, index_number_array_missing_numbers, index_array);

					for (int index_arr = 0; index_arr < value_missing_numbers; index_arr++)
					{
						array_all_combinations_line[index_line_array_all_combinations][index_arr] = missing_numbers_line[index_arr];
					}
					index_line_array_all_combinations++;
					combination_does_not_find = false;
					break;
				}
			}
			index_number_array_missing_numbers++;
		}
	}
}

bool check_on_unique_combination(vector_2d array_combinations, vector<char> combination, int value_missing_numbers)
{
	bool combination_is_unique = true;

	for (int index_line = 0; index_line < factorial(value_missing_numbers); index_line++)
	{
		string combination_1, combination_2;

		for (int index_column = 0; index_column < value_missing_numbers; index_column++)
		{
			combination_1 += to_string(array_combinations[index_line][index_column]);
			combination_2 += to_string(combination[index_column]);
		}

		if (combination_1 == combination_2)
		{
			combination_is_unique = false;
			return combination_is_unique;
		}

	}
	return combination_is_unique;
}

bool verify_on_solution(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], char* numbers)
{
	bool sudoku_is_solved = true;

	for (int index_line = 0; index_line < size_line_2d_array; index_line++)
	{
		find_missing_numbers_line(arr_2d[index_line], status_cubes, numbers, index_line);

		if (missing_numbers_line.size() != 0)
		{
			sudoku_is_solved = false;
			return sudoku_is_solved;
		}
	}

	for (int index_column = 0; index_column < size_column_2d_array; index_column++)
	{
		find_missing_numbers_column(arr_2d, status_cubes, numbers, index_column);

		if (missing_numbers_column.size() != 0)
		{
			sudoku_is_solved = false;
			return sudoku_is_solved;
		}
	}

	for (int index_figure = 0; index_figure < size_figure_3d_array; index_figure++)
	{
		find_missing_numbers_cube(arr_3d[index_figure], status_cubes, numbers, index_figure, size_line_3d_array, size_column_3d_array);

		if (missing_numbers_cube.size() != 0)
		{
			sudoku_is_solved = false;
			return sudoku_is_solved;
		}
	}

	return sudoku_is_solved;
}

void paste_combination_in_sudoku(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*arr_2d)[size_column_2d_array], string(*status_cubes)[size_column_2d_array], int index_line)
{
	int index_array_missing_numbers = 0;

	for (int index_column = 0; index_column < size_column_2d_array; index_column++)
	{
		if (status_cubes[index_line][index_column] == "free")
		{
			int index_line_3d_array = index_line % size_line_3d_array;
			int index_column_3d_array = index_column % size_column_3d_array;
			int index_figure = (index_line / size_line_3d_array) * size_line_3d_array + (index_column / size_column_3d_array);

			set_parametr(arr_3d, arr_2d, status_cubes, index_figure, index_line_3d_array, index_column_3d_array, missing_numbers_line[index_array_missing_numbers], "free");

			index_array_missing_numbers++;
		}
	}
}

void zeroint_empty_cases(char(*arr_2d)[size_column_2d_array], char(*arr_3d)[size_line_3d_array][size_column_3d_array], string(*status_cases)[size_column_2d_array])
{
	for (int index_line = 0; index_line < size_line_2d_array; index_line++)
	{
		for (int index_column = 0; index_column < size_column_2d_array; index_column++)
		{
			if (status_cases[index_line][index_column] == "free")
			{
				int index_line_3d_array = index_line % size_line_3d_array;
				int index_column_3d_array = index_column % size_column_3d_array;
				int index_figure = (index_line / size_line_3d_array) * size_line_3d_array + (index_column / size_column_3d_array);

				set_parametr(arr_3d, arr_2d, status_cases, index_figure, index_line_3d_array, index_column_3d_array, '0', "free");
			}
		}
	}
}


void sudoku_solver()
{
	bool cycle_cube_has_unique_number = true;

	char arr_3d[size_figure_3d_array][size_line_3d_array][size_column_3d_array]{};
	char arr_2d[size_line_2d_array][size_column_2d_array]{};
	char numbers[16] = { '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G' };
	int previous_values_case[size_line_2d_array * size_line_2d_array][size_column_2d_array]{};
	string status_cases[size_line_2d_array * size_line_2d_array][size_column_2d_array];

	ifstream Field_Sudoku("Sudoku_field.txt");

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Set parametrs
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	default_settings(status_cases, size_line_2d_array, size_column_2d_array);

	for (int index_line = 0; index_line < size_line_2d_array; index_line++)
	{
		string line;

		getline(Field_Sudoku, line);

		for (int index_column = 0; index_column < line.size(); index_column++)
		{
			char number = line[index_column];
			int index_figure_3d_array = (index_line / size_line_3d_array) * size_line_3d_array + (index_column / size_column_3d_array);
			int line_3d_array = index_line % size_line_3d_array;
			int column_3d_array = index_column % size_column_3d_array;

			if (number != '0')
			{
				set_parametr(arr_3d, arr_2d, status_cases, index_figure_3d_array, line_3d_array, column_3d_array, number, "busy");
			}

		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////
	// Output
	/////////////////////////////////////////////////////////////////////////////////////////

	print_array(arr_2d, size_line_2d_array, size_column_2d_array);
	cout << endl << endl;

	///////////////////////////////////////////////////////////////////////////////////////
	// Solution without combinatory
	////////////////////////////////////////////////////////////////////////////////////////

	while (cycle_cube_has_unique_number)
	{
		cycle_for_cube(arr_3d, arr_2d, status_cases, previous_values_case, cycle_cube_has_unique_number, numbers);
	}

	/////////////////////////////////////////////////////////////////////////////////////////
	// Output
	/////////////////////////////////////////////////////////////////////////////////////////

	///////////
	// Debug
	//////////


	//////////
	//////////

	cout << "Solution without combinatory\n\n";
	print_array(arr_2d, size_line_2d_array, size_column_2d_array);
	cout << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////////////
	// Check: "Sudoku is solved?"
	////////////////////////////////////////////////////////////////////////////////////////

	if (verify_on_solution(arr_3d, arr_2d, status_cases, numbers))
	{
		cout << "Sudoku is solved\n";
		return;
	}
	else
		cout << "Sudoku isn't solved\n";


	////////////////////////////////////////////////////////////////////////////////////////
	// Solution with combinatory
	////////////////////////////////////////////////////////////////////////////////////////


	cout << "Sudoku is solved\n";

	system("pause");
}
void print_array(vector<vector<char> > vector, int index_line_arr, int index_column_arr)
{
	for (int index_line = 0; index_line < index_line_arr; index_line++)
	{
		for (int index_column = 0; index_column < index_column_arr; index_column++)
		{
			cout << vector[index_line][index_column] << " ";
		}
		cout << endl;
	}
}

void print_array(vector <char> arr)
{
	for (int index = 0; index < arr.size(); index++)
	{
		cout << arr[index] << " ";
	}

}


void print_array(char(*array)[size_column_2d_array], int size_line, int size_column) // need yet
{
	for (int index_line = 0; index_line < size_line; index_line++)
	{
		for (int index_column = 0; index_column < size_column; index_column++)
		{
			cout << array[index_line][index_column] << " ";
		}
		cout << endl;
	}
}

bool Exist_number_in_the_line(char* arr, string(*status_cube)[size_column_2d_array], int size_column, int index_line, char number)
{
	bool exist = false;

	for (int index_column = 0; index_column < size_column; index_column++)
	{
		if (arr[index_column] == number)
		{
			exist = true;
			break;
		}
	}

	return exist;
}

bool Exist_number_in_the_column(char(*arr)[size_column_2d_array], string(*status_cube)[size_column_2d_array], int size_line, int index_column, char number)
{
	bool exist = false;

	for (int index_line = 0; index_line < size_line; index_line++)
	{
		if (arr[index_line][index_column] == number)
		{
			exist = true;
			break;
		}
	}

	return exist;
}

bool Exist_number_cube(char(*arr)[size_column_3d_array], string(*status_cases)[size_column_2d_array], int index_figure, int size_line, int size_column, char number)
{
	bool exist = false;

	for (int index_line = 0; index_line < size_line; index_line++)
	{
		for (int index_column = 0; index_column < size_column; index_column++)
		{
			if (arr[index_line][index_column] == number)
			{
				exist = true;
				break;
			}
		}
	}

	return exist;
}

void default_settings(string(*status_case)[size_column_2d_array], int size_line, int size_column)
{
	for (int index_line = 0; index_line < size_line; index_line++)
	{
		for (int index_column = 0; index_column < size_column; index_column++)
		{
			status_case[index_line][index_column] = "free";
		}
	}
}

void set_parametr(char(*arr_3d)[size_line_3d_array][size_column_3d_array], char(*array)[size_column_2d_array], string(*arr_status)[size_column_2d_array], int index_figure, int line, int column, char number, string status)
{
	int index_line = (index_figure / size_line_3d_array) * size_line_3d_array + line;
	int index_column = (index_figure % size_column_3d_array) * size_column_3d_array + column;
	int index_case = (index_line * size_line_3d_array) + index_column;

	arr_3d[index_figure][line][column] = number;
	array[index_line][index_column] = number;
	arr_status[index_line][index_column] = status;
}

int char_to_int(char symbol)
{
	return symbol - '0';
}

int factorial(int number)
{
	if (number == 1 || number == 0)
		return 1;
	else
		return number * factorial(number - 1);
}

void swap_numbers(vector<char>& arr, int index_number_1, int index_number_2)
{
	int extra_variable = arr[index_number_1];

	arr[index_number_1] = arr[index_number_2];
	arr[index_number_2] = extra_variable;
}

void copy_vector(vector<char> arr_1, vector<char>& arr_2)
{
	for (int index_array = 0; index_array < arr_1.size(); index_array++)
		arr_2.push_back(arr_1[index_array]);
}
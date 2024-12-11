// Example.cpp : В этом файле вы можете отлаживать ваше задание.
// Подклчайте нужные библиотеки, пишите код, как в обычной программе

#include <iostream>
#include "Task.h"
#include <iostream>

void PrintMatrix(int** arr, int cols, int rows)
{
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
			std::cout << arr[j][i] << ' ';
		std::cout << std::endl;
	}
}

void FillMatrix(int** arr, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			std::cin >> arr[i][j];
}

int** CreateAndInitializeMatrix(int cols, int rows)
{
	if (rows <= 0 || cols <= 0) return nullptr; //если неверное кол-во строк и столбцов - выходим
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];
	FillMatrix(arr, cols, rows);
	PrintMatrix(arr, cols, rows);
	return arr;
}

int main()
{
	CreateAndInitializeMatrix(3, 3);
}


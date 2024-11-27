#include "pch.h"
#include "Task.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <regex>
using namespace std;

void Destroy2DArray(int** a, int rows)
{
	if (a)
	{
		for (int i = 0; i < rows; i++)
			delete[] a[i];
		delete[] a;
	}
}

TEST(TestTask, CreateNullMatrix) {
	int** matrix;
	EXPECT_NO_THROW(matrix = CreateAndInitializeMatrix(0, 0));
	EXPECT_TRUE(matrix == nullptr);
}

TEST(TestTask, CreateInvalidMatrix) {
	int** matrix;
	EXPECT_NO_THROW(matrix = CreateAndInitializeMatrix(-10, 5));
	EXPECT_TRUE(matrix == nullptr);
}

TEST(TestTask, Create3x3Matrix) {
	string fileNameOut = "test1out.txt";
	string fileNameIn = "test1in.txt";
	ofstream out(fileNameOut);
	ifstream in(fileNameIn);
	auto coutBuf = cout.rdbuf();
	auto cinBuf = cin.rdbuf();
	cout.rdbuf(out.rdbuf());
	cin.rdbuf(in.rdbuf());
	int** matrix;
	EXPECT_NO_THROW(matrix = CreateAndInitializeMatrix(3, 3));
	EXPECT_FALSE(matrix == nullptr);
	Destroy2DArray(matrix, 3);
	cout.rdbuf(coutBuf);
	cin.rdbuf(cinBuf);
	out.close();
	in.close();
	in.open(fileNameOut);
	stringstream ss, ss1;
	ss << in.rdbuf();
	string text = ss.str();
	in.close();
	in.open(fileNameIn);
	ss1 << in.rdbuf();
	string text1 = ss1.str();
	in.close();
	if (filesystem::exists(fileNameOut))
		filesystem::remove(filesystem::path(fileNameOut));
	text = std::regex_replace(text, std::regex("^ +| +$|( ) +"), "$1");
	text1 = std::regex_replace(text1, std::regex("^ +| +$|( ) +"), "$1");
	EXPECT_EQ(text, text1);
}

TEST(TestTask, Create1x1Matrix) {
	string fileNameOut = "test2out.txt";
	string fileNameIn = "test2in.txt";
	ofstream out(fileNameOut);
	ifstream in(fileNameIn);
	auto coutBuf = cout.rdbuf();
	auto cinBuf = cin.rdbuf();
	cout.rdbuf(out.rdbuf());
	cin.rdbuf(in.rdbuf());
	int** matrix;
	EXPECT_NO_THROW(matrix = CreateAndInitializeMatrix(1, 1));
	EXPECT_FALSE(matrix == nullptr);
	Destroy2DArray(matrix, 1);
	cout.rdbuf(coutBuf);
	cin.rdbuf(cinBuf);
	out.close();
	in.close();
	in.open(fileNameOut);
	stringstream ss, ss1;
	ss << in.rdbuf();
	string text = ss.str();
	in.close();
	in.open(fileNameIn);
	ss1 << in.rdbuf();
	string text1 = ss1.str();
	in.close();
	if (filesystem::exists(fileNameOut))
		filesystem::remove(filesystem::path(fileNameOut));
	text = std::regex_replace(text, std::regex("^ +| +$|( ) +"), "$1");
	text1 = std::regex_replace(text1, std::regex("^ +| +$|( ) +"), "$1");
	EXPECT_EQ(text, text1);
}

TEST(TestTask, Create5x2Matrix) {
	string fileNameOut = "test3out.txt";
	string fileNameIn = "test3in.txt";
	ofstream out(fileNameOut);
	ifstream in(fileNameIn);
	auto coutBuf = cout.rdbuf();
	auto cinBuf = cin.rdbuf();
	cout.rdbuf(out.rdbuf());
	cin.rdbuf(in.rdbuf());
	int** matrix;
	EXPECT_NO_THROW(matrix = CreateAndInitializeMatrix(5, 2));
	EXPECT_FALSE(matrix == nullptr);
	Destroy2DArray(matrix, 2);
	cout.rdbuf(coutBuf);
	cin.rdbuf(cinBuf);
	out.close();
	in.close();
	in.open(fileNameOut);
	stringstream ss, ss1;
	ss << in.rdbuf();
	string text = ss.str();
	in.close();
	in.open(fileNameIn);
	ss1 << in.rdbuf();
	string text1 = ss1.str();
	in.close();
	if (filesystem::exists(fileNameOut))
		filesystem::remove(filesystem::path(fileNameOut));
	text = std::regex_replace(text, std::regex("^ +| +$|( ) +"), "$1");
	text1 = std::regex_replace(text1, std::regex("^ +| +$|( ) +"), "$1");
	EXPECT_EQ(text, text1);
}
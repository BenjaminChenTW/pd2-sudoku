#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cstdio>

using namespace std;

class Sudoku {
public:
        Sudoku();
		void GiveQuestion();
		void ReadIn();
        void Solve();
private:
		void RandByNum();
		void RandByBRow(int* mapTemp);
		void RandByBColumn(int* mapTemp);
		void RandByRow(int* mapTemp);
		void RandByColumn(int* mapTemp);
		void createBlank();
		void CopyMap(int* mapTemp);
		void DrawMap(int* map);
		void solveSudoku();
		int OnlyAns();
		bool Rule(int* arr, int num);
		void fillOne();
		void fillOne(int* arr, int num, int location, int mode);
		void checkRep();
		void onlyAns(); //直接排除法
		bool finishAns();
		static const int mapSize = 144;
		int mapAll[mapSize];
		int mapTrans[mapSize];
		bool ans[mapSize][9];
		static const char mapLib[mapSize];
};

#endif

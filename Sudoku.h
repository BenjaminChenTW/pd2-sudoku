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
		void CopyMap(int* mapTemp, int* targetMap);
		void DrawMap(int* map);
		bool Solve(int* mapTrans);
		bool solveSudoku();
		bool OnlyAns();
		bool Rule(int* arr, int num);
		bool Check();
		void fillOne();
		void fillOne(int* arr, int num, int location, int mode);
		void checkRep();
		void onlyAns(int num); //直接排除法
		bool finishAns();
		static const int mapSize = 144;
		int mapAll[mapSize];
		int mapTrans[mapSize];
		bool ans[mapSize][9];
		static const char mapLib[mapSize];
		void DrawArr();
};

#endif

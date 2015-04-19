#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

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
		void CopyMap(int* mapTemp);
		void DrawMap();
		static const int mapSize = 144;
		int mapAll[mapSize];
		int mapTrans[mapSize];
		static const char mapLib[mapSize];
};

#endif

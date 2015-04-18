#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

using namespace std;

class Sudoku() {
        pubilc:
                Sudoku();
		GiveQuestion();
                ReadIn();
                Solve();
        private:
		static const int mapSize = 144;
		static const int tranSize = 81;
		int mapAll[mapSize];
		int mapTrans[tranSize];

#endif

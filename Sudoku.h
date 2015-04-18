#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

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
		static const char mapLib[tranSize]{
        		h, a, b, g, e, c, f, d, i,
        		i, d, c, f, h, b, a, g, e,
        		f, g, e, d, i, a, b, h, c,
        		a, e, d, b, c, g, h, i, f,
        		c, f, i, h, d, e, g, b, a,
        		b, h, g, a, f, i, e, c, d,
        		e, b, a, i, g, d, c, f, h,
        		d, c, h, e, b, f, i, a, g,
        		g, i, f, c, a, h, d, e, b};

#endif

#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku() {
	for (int i=0; i<mapSize; i++){
		mapAll[i]=10;
		mapTrans[i]=0;
	}
}
const char Sudoku::mapLib[mapSize] = {
	'd', 'b', 'f', 'h', 'g', 'c', 'i', 'e', 'a', 'z', 'z', 'z',
	'h', 'g', 'c', 'i', 'e', 'a', 'f', 'b', 'd', 'z', 'z', 'z',
        'i', 'e', 'a', 'f', 'b', 'd', 'h', 'g', 'c', 'z', 'z', 'z',
        'z', 'z', 'z', 'a', 'c', 'b', 'd', 'h', 'g', 'i', 'e', 'f',
        'z', 'z', 'z', 'g', 'h', 'e', 'a', 'i', 'f', 'd', 'b', 'c',
        'z', 'z', 'z', 'd', 'i', 'f', 'b', 'c', 'e', 'h', 'g', 'a',
	'a', 'c', 'g', 'b', 'd', 'h', 'z', 'z', 'z', 'f', 'i', 'e',
	'b', 'h', 'd', 'e', 'f', 'i', 'z', 'z', 'z', 'a', 'c', 'g',
        'f', 'i', 'e', 'c', 'a', 'g', 'z', 'z', 'z', 'b', 'h', 'd',
        'c', 'a', 'b', 'z', 'z', 'z', 'g', 'd', 'h', 'e', 'f', 'i',
        'g', 'd', 'h', 'z', 'z', 'z', 'e', 'f', 'i', 'c', 'b', 'a',
        'e', 'f', 'i', 'z', 'z', 'z', 'c', 'a', 'b', 'g', 'd', 'h'
};
void Sudoku::GiveQuestion() {
	srand(time(NULL));
	int mapTemp[mapSize];
	RandByNum();
	//DrawMap(mapTrans);
	//cout << 1;
	RandByBRow(mapTemp);
	CopyMap(mapTemp);
	//DrawMap(mapTrans);
	//cout << 2;
	RandByBColumn(mapTemp);
	CopyMap(mapTemp);
	//DrawMap(mapTrans);
	//cout << 3;
	RandByRow(mapTemp);
	CopyMap(mapTemp);
	//DrawMap(mapTrans);
	//cout << 4;
	RandByColumn(mapTemp);
	CopyMap(mapTemp);
	DrawMap(mapTrans);
	//cout << 5;
}
void Sudoku::RandByNum() {
	int arr[9];
	for (int i=0; i<9; i++)
		arr[i]=i+1;
	random_shuffle(arr, arr+9);
	for (int i=0; i<mapSize; i++) {
		switch (mapLib[i]) {
		case 'a': mapTrans[i] = arr[0]; break;
		case 'b': mapTrans[i] = arr[1]; break;
		case 'c': mapTrans[i] = arr[2]; break;
		case 'd': mapTrans[i] = arr[3]; break;
		case 'e': mapTrans[i] = arr[4]; break;
		case 'f': mapTrans[i] = arr[5]; break;
		case 'g': mapTrans[i] = arr[6]; break;
		case 'h': mapTrans[i] = arr[7]; break;
		case 'i': mapTrans[i] = arr[8]; break;
		case 'z': mapTrans[i] = -1; break;
		}
	}	
}
void Sudoku::RandByBRow(int* mapTemp) {
	int arr[4] = {0, 3, 6, 9};
	random_shuffle(arr, arr+4);
	for (int i=0, j=0, z=0; i<mapSize; i++, j++) {
		if (j == 36) {
			j = 0;
			z++;
		}
		mapTemp[i] = mapTrans[arr[z]*12+j];
	}
}
void Sudoku::RandByBColumn(int* mapTemp) {
	int arr[4] = {1, 4, 7, 10};
	random_shuffle(arr, arr+4);
	for (int i=0, j=0, z=0, x=0, y=0; i<mapSize; i++, j++, x++) {
		if (j == 3) {
			j = 0;
			z++;
		}
		if (z == 4) z = 0;
		if (x == 12) {
			x = 0;
			y++;
		}
		mapTemp[i] = mapTrans[j+arr[z]-1+y*12];
	}
}
void Sudoku::RandByRow(int* mapTemp) {
	int arr[3] = {1, 13, 25};
	for (int i=0; i < 4; i++) {
		random_shuffle(arr, arr+3);
		for (int j=0, z=0, x=0; j < 36; j++, z++) {
			if (z == 12) {
				z = 0;
				x++;
			}
			mapTemp[j+i*36] = mapTrans[arr[x]-1+i*36+z];
		}
	}
}
void Sudoku::RandByColumn(int* mapTemp) {
	int arr[3] = {1, 2, 3};
	/*
	for (int i=0; i < 4; i++) {
		random_shuffle(arr, arr+3);
		for (int z=0, x=0; x < 12; z++) {
			if (z == 3) {
				z = 0;
				x++;
			}
			mapTemp[z+x*12+i*3] = mapTrans[arr[z]-1+x*12+i*3];
		}
	}
	*/
	random_shuffle(arr, arr+3);
	for (int j=0, i=0; j<48; j++) {
		for (int z=0; z<3; z++) {
			mapTemp[i] = mapTrans[(arr[z]-1)+j*3];
			i++;
		}
	}
}
void Sudoku::CopyMap(int* mapTemp) {
	for (int i=0; i<mapSize; i++)
		mapTrans[i] = mapTemp[i];
}
void Sudoku::DrawMap(int* map) {
	for (int i=0; i<mapSize; i++) {
		if (!(i % 12) && i != 0) cout << endl;
		cout << ((map[i] == -1)? " ": " ") << map[i];
	}
	cout << endl;
}
//----------------------------------------------------------------------
void Sudoku::ReadIn() {
	for (int i=0; i < mapSize; i++) {
		cin >> mapAll[i];
		if (mapAll[i] == 10) {
			cout << "Data incorrect" << endl;
			exit(0);
		}
		else
			mapTrans[i] = 1;
	}
	//DrawMap(mapAll);
}
int Sudoku::OnlyAns() {
	int mapCheckTw[12]={};
	int mapCheckNi[9]={};
	int blankCtr = 0;
	int allBlank = 0;
	int cellBlank = 0;
	int onceBlank = 0;
	bool ctr = false;
	for (int i=0, z=0; i<144; i+=12, z++) { //By row
		for (int j=0; j<12; j++) {
			mapCheckTw[j] = mapAll[i+j];
			if (mapCheckTw[j] != 0 && mapCheckTw[j] != -1) {
				blankCtr++;
				ctr = true;
			}
			if (!ctr){
				allBlank++;
				onceBlank++;
			}
			ctr = false;
		}
		if (!Rule(mapCheckTw,12))
			return 0;
		if (allBlank >= 2) {
			cout << 0;
			return 2;
		}
		if (onceBlank == 1)
			fillOne(mapCheckTw, 12, i, 1);
		if (z == 3) {
			z =0;
			allBlank = 0;
		}
		onceBlank = 0;
	}
	if (blankCtr <17) {
		cout << 1;
		return 2;
	}
	blankCtr = 0;
	allBlank = 0;
	for (int i=0, z=0; i<12; i++, z++) { //Bycolumn
		for (int j=0; j<12; j++) {
			mapCheckTw[j] = mapAll[i+j*12];	
			if (mapCheckTw[j] != 0 && mapCheckTw[j] != -1) {
				ctr = true;
			}
			if (!ctr) {
				onceBlank++;
				allBlank++;
			}
			ctr = false;
		}
		if (!Rule(mapCheckTw,12))
			return 0;
		if (allBlank >= 2) {
			cout << 2;
			return 2;
		}
		if (onceBlank == 1)
			fillOne(mapCheckTw, 12, i, 2);
		if (z == 3) {
			z =0;
			allBlank = 0;
		}
		onceBlank = 0;
	}
	allBlank = 0;
	for (int i=0; i<16; i++) {
		for (int j=0; j<9; j++) {
			mapCheckNi[j] = mapAll[(i/4)*36+(i%4)*3+(j/3)*12+(j%3)];
			if (mapCheckNi[j] != 0 && mapCheckNi[j] != -1) {
				ctr = true;
			}
			if (!ctr)
				allBlank++;
			ctr = false;
		}
		if (!Rule(mapCheckNi, 9))
			return 0;
		if (allBlank == 1)
			fillOne(mapCheckNi, 9, i, 3);
		else if (allBlank > 0) {
			allBlank = 0;
			cellBlank++;
		}
		if (cellBlank >= 4) {
			cout << 3;
			return 2;
		}
	}
	return 1;
}
bool Sudoku::Rule(int* arr, int num) {
	int numExist[9] = {};
	for (int i=0; i<num; i++)
		if (arr[i] != -1 && arr[i] != 0)
			numExist[arr[i]-1]++;
	for (int i=0; i<9; i++)
		if (numExist[i] > 1)
			return false;
	return true;
}
void Sudoku::fillOne(int* arr, int num, int location, int mode) {
	int numExist[9] = {};
	for (int i=0; i<num; i++)
		if (arr[i] != -1 && arr[i] != 0)
			numExist[arr[i]-1]++;
	for (int i=0; i<9; i++) {
		if (numExist[i] == 0 && mode == 1) {
			for (int j=0; j<num; j++)
				if (arr[j] == 0)
					mapAll[location+j] = i+1;
		}
		else if (numExist[i] == 0 && mode == 2) {
			for (int j=0; j<num; j++)
				if (arr[j] == 0)
					mapAll[j*12+location] = i+1;
		}
		else if (numExist[i] == 0 && mode == 3) {
			for (int j=0; j<num; j++)
				if (arr[j] == 0)
					mapAll[(location/4)*36+(location%4)*3+(j/3)*12+(j%3)] = i+1;
		}
	}
}
void Sudoku::Solve() {
	int mode = OnlyAns();
	if (mode == 0) {
		cout << 0 << endl;
	}
	else if (mode == 1) {
		int oneToten[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		cout << 1 << endl;
		DrawMap(mapAll);
	}
	else if (mode == 2) {
		cout << 2 << endl;
	}
}

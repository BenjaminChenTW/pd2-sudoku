#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku() {
	for (int i=0; i<mapSize; i++){
		mapAll[i]=0;
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
	DrawMap();
	cout << 1;
	RandByBRow(mapTemp);
	CopyMap(mapTemp);
	DrawMap();
	cout << 2;
	RandByBColumn(mapTemp);
	CopyMap(mapTemp);
	DrawMap();
	cout << 3;
	RandByRow(mapTemp);
	//CopyMap(mapTemp);
	//DrawMap();
	cout << 4;
	RandByColumn(mapTemp);
	CopyMap(mapTemp);
	DrawMap();
	cout << 5;
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
}
void Sudoku::CopyMap(int* mapTemp) {
	for (int i=0; i<mapSize; i++)
		mapTrans[i] = mapTemp[i];
}
void Sudoku::DrawMap() {
	for (int i=0; i<mapSize; i++) {
		if (!(i % 12)) cout << endl;
		cout << ((mapTrans[i] == -1)? " ": "  ") << mapTrans[i];
	}
	cout << endl;
}
void Sudoku::ReadIn() {

}
void Sudoku::Solve() {

}

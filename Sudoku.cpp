#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku() {
	mapAll[]={};
	mapTrans[]={};
}
Sudoku::GiveQuestion() {
	srand(time(NULL));
	int arr[9];
	for (int i=1; i<=9; i++)
		arr[i]=i;
	random_shuffle(arr, arr+9);
	for (int i=0; i<tranSize; i++) {
	switch (maplib[i]) {
	case a:	mapTrans[i] = arr[0]; break;
	case b: mapTrans[i] = arr[1]; break;
	case c: mapTrans[i] = arr[2]; break;
	case d: mapTrans[i] = arr[3]; break;
	case e: mapTrans[i] = arr[4]; break;
	case f: mapTrans[i] = arr[5]; break;
	case g: mapTrans[i] = arr[6]; break;
	case h: mapTrans[i] = arr[7]; break;
	case i: mapTrans[i] = arr[8]; break;
	}
	
}
Sudoku::ReadIn() {

}
Sudoku::Solve() {

}

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
    'g', 'd', 'h', 'z', 'z', 'z', 'e', 'f', 'i', 'c', 'a', 'b',
    'e', 'f', 'i', 'z', 'z', 'z', 'c', 'a', 'b', 'g', 'd', 'h'
};
void Sudoku::GiveQuestion() {
	srand(time(NULL));
	int mapTemp[mapSize];
	RandByNum();
	RandByBRow(mapTemp);
	CopyMap(mapTemp, mapTrans);
	RandByBColumn(mapTemp);
	CopyMap(mapTemp, mapTrans);
	RandByRow(mapTemp);
	CopyMap(mapTemp, mapTrans);
	RandByColumn(mapTemp);
	CopyMap(mapTemp, mapTrans);
	createBlank();
	DrawMap(mapTrans);
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
void Sudoku::createBlank() {
    int mapTemp[mapSize];
    CopyMap(mapTrans, mapTemp);
    do{
        for (int i=0; i<mapSize; i++)
            if (mapTemp[i] != -1)
                if (!(rand() % 3))
                    mapTemp[i] = 0;
    }while(!Solve(mapTrans));
    CopyMap(mapTemp, mapTrans);
    int numTemp;
    while(true){
        numTemp = rand() % mapSize;
        if (mapTrans[numTemp] != 0 && mapTrans[numTemp] != -1) {
            CopyMap(mapTrans, mapTemp);
            mapTemp[numTemp] = 0;
            if (Solve(mapTemp))
                CopyMap(mapTemp, mapTrans);
            else
                break;
        }
    }
}
void Sudoku::CopyMap(int* mapTemp, int* targetMap) {
	for (int i=0; i<mapSize; i++)
		targetMap[i] = mapTemp[i];
}
void Sudoku::DrawMap(int* map) {
	for (int i=0; i<mapSize; i++) {
		if (!(i % 12) && i != 0) cout << endl;
		cout <<((map[i] == -1)? "" : " ")<< map[i] << " ";
	}
	cout << endl;
}
//----------------------------------------------------------------------
void Sudoku::ReadIn() {
	for (int i=0; i < mapSize; i++) {
		cin >> mapAll[i];
		if (mapAll[i] <= 9 && mapAll[i] >= -1){
            if (mapAll[i] == 0)
                mapTrans[i] = 1;
		}
		else {
			cerr << "Data incorrect" << endl;
			exit(0);
		}
	}
	//DrawMap(mapAll);
}
void Sudoku::Solve() {
	if (!OnlyAns()) {
		cout << 0 << endl;
	}
    else if (solveSudoku()) {
		cout << 1 << endl;
		DrawMap(mapAll);
	}
	else {
		cout << 2 << endl;
	}
}
bool Sudoku::Solve(int* mapTrans) {
    CopyMap(mapTrans, mapAll);
	if (!OnlyAns()) {
		return false;
	}
    else if (solveSudoku()) {
		return true;
	}
	else {
		return false;
	}
}
bool Sudoku::solveSudoku(){
    int ctr = 0;
    for (int i=0; i < mapSize; i++){
        if (mapAll[i] == 0)
            for (int j=0; j < 9; j++)
                ans[i][j] = true;
        else if (mapAll[i] == -1)
            for (int j=0; j < 9; j++)
                ans[i][j] = false;
        else {
            for (int j=0; j < 9; j++)
                ans[i][j] = false;
            ans[i][mapAll[i]-1] = true;
        }
    }
    do{
        fillOne();
        checkRep();
        onlyAns(1);
        ctr++;
        if (ctr >= 5) {
            return false;
        }
    }while(!finishAns());
    //cout << ctr << endl;
    return true;
}
bool Sudoku::OnlyAns() {
    if (!Check())
        return false;
	int mapCheckTw[12]={};
	int mapCheckNi[9]={};
	for (int i=0; i<144; i+=12) { //By row
		for (int j=0; j<12; j++) {
			mapCheckTw[j] = mapAll[i+j];
		}
		if (!Rule(mapCheckTw,12)) {
			return false;
		}
	}
	for (int i=0; i<12; i++) { //By column
		for (int j=0; j<12; j++) {
			mapCheckTw[j] = mapAll[i+j*12];
		}
		if (!Rule(mapCheckTw,12)) {
			return false;
		}
	}
	for (int i=0; i<16; i++) {
		for (int j=0; j<9; j++) {
			mapCheckNi[j] = mapAll[(i/4)*36+(i%4)*3+(j/3)*12+(j%3)];
		}
		if (!Rule(mapCheckNi, 9)) {
			return false;
		}
	}
	return true;
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
bool Sudoku::Check(){
    int ctr =0;
    int mapTemp[mapSize] = {};
    for (int i=0; i<mapSize; i++){
        if (mapAll[i] == -1){
            mapTemp[i] = -1;
            ctr++;
        }
    }
    if (ctr != 36)
        return false;
    for (int x=0, y=0; x<mapSize; x++){
        if (mapTemp[x] == -1){
            if ((x % 3) != 0)
                return false;
            for (int j=0; j<9; j++) {
                if (mapTemp[x+j%3+(j/3)*12] != -1)
                    return false;
            }
            y++;
            x = y*36-1;
        }
    }
	return true;
}
void Sudoku::fillOne() {
	int mapCheckTw[12]={};
	int mapCheckNi[9]={};
	int blankCtr = 0;
	for (int i=0, z=0; i<144; i+=12, z++) { //By row
		for (int j=0; j<12; j++) {
			mapCheckTw[j] = mapAll[i+j];
			if (mapCheckTw[i] == 0)
				blankCtr++;
		}
		if (blankCtr == 1)
			fillOne(mapCheckTw, 12, i, 1);
		blankCtr = 0;
	}
	for (int i=0; i<12; i++) { //Bycolumn
		for (int j=0; j<12; j++) {
			mapCheckTw[j] = mapAll[i+j*12];
			if (mapCheckTw[j] == 0)
				blankCtr++;
		}
		if (blankCtr == 1)
			fillOne(mapCheckTw, 12, i, 2);
		blankCtr = 0;
	}
	for (int i=0; i<16; i++) {
		for (int j=0; j<9; j++) {
			mapCheckNi[j] = mapAll[(i/4)*36+(i%4)*3+(j/3)*12+(j%3)];
			if (mapCheckNi[j] == 0 )
				blankCtr++;
		}
		if (blankCtr == 1)
			fillOne(mapCheckNi, 9, i, 3);
	}
}
void Sudoku::fillOne(int* arr, int num, int location, int mode) {
	int numExist[9] = {};
	for (int i=0; i<num; i++)
		if (arr[i] != -1 && arr[i] != 0)
			numExist[arr[i]-1]++;
	for (int i=0; i<9; i++) {
		if (numExist[i] == 0 && mode == 1) {
			for (int j=0; j<num; j++)
				if (arr[j] == 0){
					mapAll[location+j] = i+1;
					mapTrans[location+j] = 0;
                    for (int t=0; t<9; t++){
                        if (t != i)
                            ans[location+j][t] = false;
                    }
				}
		}
		else if (numExist[i] == 0 && mode == 2) {
			for (int j=0; j<num; j++)
				if (arr[j] == 0){
					mapAll[j*12+location] = i+1;
					mapTrans[j*12+location] = 0;
                    for (int t=0; t<9; t++){
                        if (t != i)
                            ans[j*12+location][t] = false;
                    }
				}
		}
		else if (numExist[i] == 0 && mode == 3) {
			for (int j=0; j<num; j++)
				if (arr[j] == 0){
					mapAll[(location/4)*36+(location%4)*3+(j/3)*12+(j%3)] = i+1;
					mapTrans[(location/4)*36+(location%4)*3+(j/3)*12+(j%3)] = 0;
                    for (int t=0; t<9; t++){
                        if (t != i)
                            ans[(location/4)*36+(location%4)*3+(j/3)*12+(j%3)][t] = false;
                    }
				}
		}
	}
}
void Sudoku::checkRep(){
    for (int i=0; i < mapSize; i++){
        if (mapTrans[i] == 1){
            for (int j=0; j < 12; j++){ // BY ¾î
                if ((i%12)!=j){
                    if (mapTrans[(i/12)*12+j] == 0 && mapAll[(i/12)*12+j] != -1)
                        ans[i][mapAll[(i/12)*12+j]-1] = false;
                }
            }
            for (int j=0; j < 12; j++){ // BY ª½
                if (i!=(j+(i/12)*12)){
                    if (mapTrans[i%12+j*12] == 0 && mapAll[i%12+j*12] != -1)
                        ans[i][mapAll[i%12+j*12]-1] = false;
                }
            }
            for (int j=0; j < 9; j++){ // BY ®c
                if (mapTrans[(i/36)*36+(((i-(i/36)*36)%12)/3)*3+(j/3)*12+j%3] == 0 && mapAll[(i/36)*36+(((i-(i/36)*36)%12)/3)*3+(j/3)*12+j%3] != -1)
                    ans[i][mapAll[(i/36)*36+(((i-(i/36)*36)%12)/3)*3+(j/3)*12+j%3]-1] = false;
            }
        }
    }
}
void Sudoku::onlyAns(int num){
    for (int i=0; i < mapSize; i++){
        if (mapTrans[i] == 1){
            for (int j=0, ctr=0; j < 9; j++, ctr = 0){ // BY ¾î
                for (int t=0; t<12; t++){
                    if (ans[(i/12)*12+t][j])
                        ctr++;
                }
                if (ctr == 1 && ans[i][j] == true){
                    mapAll[i] = j+1;
                    mapTrans[i] = 0;
                    for (int t=0; t<9; t++){
                        if (t != j)
                            ans[i][t] = false;
                    }
                }
            }
        }
    }
    for (int i=0; i < mapSize; i++){
        if (mapTrans[i] == 1){
            for (int j=0, ctr=0; j < 9; j++, ctr = 0){ // BY ª½
                for (int t=0; t<12; t++){
                    if (ans[i%12+t*12][j])
                        ctr++;
                }
                if (ctr == 1 && ans[i][j] == true){
                    mapAll[i] = j+1;
                    mapTrans[i] = 0;
                    for (int t=0; t<9; t++){
                        if (t != j)
                            ans[i][t] = false;
                    }
                }
            }
        }
    }
    for (int i=0; i < mapSize; i++){
        if (mapTrans[i] == 1){
            for (int j=0, ctr=0; j < 9; j++, ctr = 0){ // BY ®c
                for (int t=0; t<9; t++){
                    if (ans[(i/36)*36+(((i-(i/36)*36)%12)/4)*4+(j/3)*12+j%3][j])
                        ctr++;
                }
                if (ctr == 1 && ans[i][j] == true){
                    mapAll[i] = j+1;
                    mapTrans[i] = 0;
                    for (int t=0; t<9; t++){
                        if (t != j)
                            ans[i][t] = false;
                    }
                }
            }
        }
    }
}
bool Sudoku::finishAns(){
    for (int i=0; i<mapSize; i++){
        if (mapTrans[i] == 1) return false;
    }
    return true;
}
void Sudoku::DrawArr(){
    for (int i=0; i < mapSize; i++){
        cout << "#" << i+1 << ": ";
        for (int j=0; j<9; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for (int i=0; i<12; i++){
        for (int j=0; j<12; j++){
            cout << mapTrans[i*12+j] << " ";
        }
        cout << endl;
    }
}

all: GiveQuestion.o SolveQuestion.o Sudoku.o
	g++ -g GiveQuestion.o Sudoku.o -o give_question
	g++ -g SolveQuestion.o Sudoku.o -o solve

GiveQuestion.o: GiveQuestion.cpp Sudoku.h
	g++ -g -c GiveQuestion.cpp -o GiveQuestion.o

SolveQuestion.o: SolveQuestion.cpp Sudoku.h
	g++ -g -c SolveQuestion.cpp -o SolveQuestion.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -g -c Sudoku.cpp -o Sudoku.o

clean:
	rm *.o give_question solve

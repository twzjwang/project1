main: Sudoku.o solve.o
	g++ -o solve solve.o Sudoku.o
	g++ -o give give.o Sudoku.o
 
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

solve.o: solve.cpp Sudoku.h
	 g++ -c solve.cpp

give.o: give.cpp Sudoku.h
	g++ -c give.cpp


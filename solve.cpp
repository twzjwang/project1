#include <iostream>
#include <stdlib.h>
#include "Sudoku.h"
using namespace std;

int main() {
	Sudoku ss;
	ss.ReadIn();
	ss.Solve();
	
	return 0;
}

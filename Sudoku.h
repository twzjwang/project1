#include <iostream>
#include <time.h> 
#include <stdlib.h>
//#include<stdlib.h>
//#include <windows.h>
using namespace std;

class Sudoku{
public:
	
	void GiveQuestion();
	
	void ReadIn();
	
	void Solve();
	
	int Solve_2();
	
	//test blank
	void test_blank(int i);
	void test_blank_2(int i);	

	
	//print current map	
	void print_map();
	
	//check : correct or not
	bool check_map();
	bool check_map_2();
	
private:
	int map[144];
	int for_test[144];
};

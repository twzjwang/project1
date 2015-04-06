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
	
	void Solve2();
	
	//test blank
	void test_blank(int i);	

	
	//print current map	
	void print_map();
	
	//check : correct or not
	bool check_map();
	
private:
	int map[144];
	int ans[144];	
	int ans_num;
};

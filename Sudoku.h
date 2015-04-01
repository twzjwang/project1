#include <iostream>
using namespace std;

class Sudoku{
public:
	
	void GiveQuestion();
	
	void ReadIn();
	
	void Solve();
	
	//test blank
	void test_blank(int i);
	
	//print current map	
	void print_map();
	
	//check : correct or not
	bool check_map();
	
private:
	int map[144];
};

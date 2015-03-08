#include<iostream>
#include<string>
#include"Cell.h"
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;

class Board{
public:
	vector<vector<Cell>> cells_;
	Board(int row_num, int col_num){
		cells_.assign(row_num, vector<Cell>(col_num));
	}
	static Board LoadProblem(string path);
};
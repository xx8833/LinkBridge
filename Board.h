#include<iostream>
#include"Cell.h"
#include<vector>
using namespace std;

class Board{
public:
	vector<vector<Cell>> cells_;
	Board(int row_num, int col_num){
		cells_.assign(row_num, vector<Cell>(col_num));
	}
};
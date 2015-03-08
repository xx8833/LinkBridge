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
	static Board LoadProblem(string path)
	{
		std::ifstream ifs;
	    ifs.open(path, std::ifstream::in);
		if(!ifs.is_open())
		{
			cerr<<"Load File Open Failure.\n";
			exit(-1);
		}
		int rows, columns;
		ifs >> rows >> columns;
		Board board(rows, columns);
		for(auto & row : board.cells_)
			for(auto & cell : row)
		{
			string cell_info;
			ifs >> cell_info;
			cell.Load(cell_info);
		}
		return board;
	}
};
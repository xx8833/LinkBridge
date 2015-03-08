#include"Board.h"

Board Board::LoadProblem(string path)
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
		for(int i=0;i<board.cells_.size();i++)
			for(int j=0;j<board.cells_[0].size();j++)
		{
			string cell_info;
			ifs >> cell_info;
			board.cells_[i][j].Load(cell_info);
		}
		return board;
	}
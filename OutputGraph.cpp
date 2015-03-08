#include<iostream>
#include<Board.h>
#include<fstream>
using namespace std;

const string fileName = "OutputGraph.html";
const int color_list[20][3] = {{255,255,255},{0,0,255},{0,255,0},{255,0,0},{255,0,255},{0,255,255},{255,255,0},
{0,50,50},{50,0,50},{50,50,0},{255,100,100},{100,255,100},{100,100,255},{255,255,50},{255,50,255},{50,255,255},
{10,150,10},{150,10,10},{10,10,150},{150,150,150}};

void ToHtml(Board BD1){
	ofstream fout;
	fout.open(fileName.c_str());
	fout<<"<!DOCTYPE html>"<<endl;
    fout<<"<html>"<<endl;
	fout<<"<body>"<<endl<<endl;
	fout<<"<h1>Solved Result:</h1>"<<endl<<endl;
	fout<<"<svg width=\"1000\" height=\"1000\">"<<endl;

	for(int i=0; i<BD1.cells_.size(); i++){
		for(int j=0; j<BD1.cells_[0].size();j++){
			fout<<"<rect x=\""<<i*20<<"\"";
			fout<<"y=\""<<j*20<<"\"";
			fout<<"width=\"20\" height=\"20\" style=\"fill:rgb("<<color_list[BD1.cells_[i][j].curr_color][0]<<","<<color_list[BD1.cells_[i][j].curr_color][1]<<","<<color_list[BD1.cells_[i][j].curr_color][2]<<");stroke-width:3;stroke:rgb(0,0,0)\" />"<<endl;;
		}
	}

	fout<<"</svg>"<<endl;
	fout<<"<body>"<<endl;
	fout<<"<html>"<<endl;
	fout.close();
	return;
}

int main(){
	Board BD(3,3);
	BD.cells_[0][0].curr_color = 1;BD.cells_[2][2].curr_color = 1;
	BD.cells_[1][0].curr_color = 10;BD.cells_[0][1].curr_color = 10;
	ToHtml(BD);
	return true;
}
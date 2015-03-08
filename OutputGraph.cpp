#include<iostream>
#include<fstream>
#include"Board.h"
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
			if (BD1.cells_[i][j].is_source){
				fout << "<rect x=\"" << i * 40 + 100 << "\"";
				fout << "y=\"" << j * 40 + 100 << "\"";
				fout << "width=\"40\" height=\"40\" style=\"fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)\" />" << endl;
				fout << "<circle cx=\"" << i * 40 + 120 << "\"";
				fout << "cy=\"" << j * 40 + 120 << "\"";
				fout << "r=\"20\" style=\"fill:rgb(" << color_list[BD1.cells_[i][j].color][0] << "," << color_list[BD1.cells_[i][j].color][1] << "," << color_list[BD1.cells_[i][j].color][2] << ");stroke-width:3;stroke:rgb(0,0,0)\" />" << endl;
			}
			else{
				fout << "<rect x=\"" << i * 40 + 100 << "\"";
				fout << "y=\"" << j * 40 + 100 << "\"";
				fout << "width=\"40\" height=\"40\" style=\"fill:rgb(" << color_list[BD1.cells_[i][j].color][0] << "," << color_list[BD1.cells_[i][j].color][1] << "," << color_list[BD1.cells_[i][j].color][2] << ");stroke-width:3;stroke:rgb(0,0,0)\" />" << endl;;
			}
			if(BD1.cells_[i][j].bridge){
				fout<<"<rect x=\""<<i*40+10+100<<"\"";
				fout<<"y=\""<<j*40+100<<"\"";
				fout<<"width=\"20\" height=\"40\" style=\"fill:rgb("<<color_list[BD1.cells_[i][j].colorb][0]<<","<<color_list[BD1.cells_[i][j].colorb][1]<<","<<color_list[BD1.cells_[i][j].colorb][2]<<");stroke-width:3;stroke:rgb(0,0,0)\" />"<<endl;;
			}
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
	BD.cells_[0][0].color = 1; BD.cells_[2][2].color = 1; BD.cells_[0][0].is_source = true;
	BD.cells_[1][0].color = 10; BD.cells_[0][1].color = 10; BD.cells_[2][2].is_source = true;
	BD.cells_[1][1].color = 5; BD.cells_[1][1].colorb = 7;BD.cells_[1][1].bridge = true;
	ToHtml(BD);
	return true;
}
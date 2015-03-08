#include<iostream>
using namespace std;

class Cell{
public:
	int color, colorb;
	bool is_source;
	bool bridge;
    int Load(string input);
    Cell():color(0),colorb(0),is_source(false),bridge(true){}
};
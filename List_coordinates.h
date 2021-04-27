#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class List_coordinates {
public:
	List_coordinates(const char* file_name);
	~List_coordinates();
	double arr_position[17][2];
private:
	ifstream list;
};
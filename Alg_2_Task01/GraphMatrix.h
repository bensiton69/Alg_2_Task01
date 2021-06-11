#pragma once
#include  <iostream>
#include <vector>
using namespace std;

class GraphMatrix
{
friend ostream& operator<<(ostream&, const GraphMatrix&);
public:
	GraphMatrix(int n, double p);
	GraphMatrix(int n);
	int Diameter();
	void BFS(int start);
	int n;
	double p;
	std::vector<std::vector<int>> matrix;
	vector<int> deg_V;
};


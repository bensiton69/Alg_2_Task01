#include <stdlib.h>
#include <iostream>
#include <vector>
#include "GraphMatrix.h"
using namespace std;
//vector<vector<int>> GenerateGraph(int n, double p);

void main()
{
	int n;
	double p;
	//cout << "Insert Number for n: ";
	//cin >> n;
	//cout << "Insert Number for p: ";
	//cin >> p;
	//GenerateGraph(n, p);
	//cout <<( "----------") << endl << "first graph:" << endl;
	//GraphMatrix graphMatrix1(5, 0.35);
	//cout << graphMatrix1;
	////graphMatrix1.BFS(3);
	//cout << ("----------") << endl << "second graph:" << endl;
	//GraphMatrix graphMatrix2(n, p);
	//cout << graphMatrix2;
	//cout << ("----------") << endl<< "third graph:" << endl;
	//GraphMatrix graphMatrix3(n, p);
	//cout << graphMatrix3;
	cout << ("----------") << endl;
	GraphMatrix graph_matrix1(5);
	cout << graph_matrix1;
	//graph_matrix1.BFS(1);
	cout << ("----------") << endl;
	GraphMatrix graph_matrix2(5);
	cout << graph_matrix2;
	cout << ("----------") << endl;
	GraphMatrix graph_matrix3(5);
	cout << graph_matrix3;
	cout << ("----------") << endl;
	GraphMatrix graph_matrix4(5);
	cout << graph_matrix4;
	cout << ("----------") << endl;
	GraphMatrix graph_matrix5(5);
	cout << graph_matrix5;
	cout << ("----------") << endl;
	GraphMatrix graph_matrix6(5);
	cout << graph_matrix6;
	//graph_matrix1.BFS(2);
}

//vector<vector<int>> GenerateGraph(int n, double p)
//{
//	n++;
//	std::vector< vector<int> > matrix;
//	matrix.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		matrix[i].resize(n);
//	}
//	for (int i = 0; i < n; i++)
//		matrix[0][i] = matrix[i][0] = i;
//	int j = 0;
//	for (int i = 1; i < n; i++)
//	{
//		j++;
//		for (j ; j < n; j++)
//		{
//			if (i==j) continue;
//			double q = (double)rand() / RAND_MAX;
//			if (q < p)
//				matrix[j][i] = matrix[i][j] = 1;
//		}
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{     
//			cout<< matrix[i][j]<<"  ";
//		}
//		cout << endl;
//	}
//	return matrix;
//}
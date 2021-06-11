#include <fstream>
#include<iostream>
#include "Graph.h"
void PrintToCSVFile(double i_ArrayOfP[], double i_inputCounter[], string i_String);
using namespace std;
#define NumOfP 10
#define NumOfGraph 500
int main()
{
	int V = 500;
	double arrayOfP1[10] = { 0.001,0.005,0.007,0.009,0.01,0.013,0.016,0.018,0.019,0.02 };
	double arrayOfP2[10] = { 0.001,0.02,0.03,0.04,0.05,0.162,0.1621,0.1622,0.1623, 0.1624 };
	double arrayOfcounter1[10] = { 0 };
	double arrayOfcounter2[10] = { 0 };
	double arrayOfcounter3[10] = { 0 };
	for (int i = 0; i < NumOfP; i++)
	{
		int counterOfT1 = 0;
		int counterOfT3 = 0;
		double P = arrayOfP1[i];
		for (int j = 0; j < NumOfGraph; j++)
		{
			cout << j << " ";
			Graph g(V, P);
			g.Threshold1AND3();
			if (g.m_isConnected)
				counterOfT1++;
			if (g.m_isIsolated)
				counterOfT3++;
		}
		arrayOfcounter1[i] = counterOfT1 / (double)NumOfGraph;
		arrayOfcounter3[i] = counterOfT3 / (double)NumOfGraph;
	}
	for (int i = 0; i < NumOfP; i++)
	{
		int counterOfT2 = 0;
		double P = arrayOfP2[i];
		for (int j = 0; j < NumOfGraph; j++)
		{
			cout << j << " ";
			Graph g(V, P);
			g.Threshold2();
			if (g.m_diam == 2)
				counterOfT2++;
		}
		arrayOfcounter2[i] = counterOfT2 / (double)NumOfGraph;
	}
	PrintToCSVFile(arrayOfP1, arrayOfcounter1, "Proposition 1");
	PrintToCSVFile(arrayOfP2, arrayOfcounter2, "Proposition 2");
	PrintToCSVFile(arrayOfP1, arrayOfcounter3, "Proposition 3");
	cout << endl << "Done" << endl;
	return 0;
}
void PrintToCSVFile(double i_ArrayOfP[], double i_inputCounter[], string i_String)
{
	fstream fout;
	fout.open("Simulation.csv", ios::out | ios::app);
	fout << "P" << ", ";
	for (int i = 0; i < 10; i++)
	{
		fout << i_ArrayOfP[i] << ", ";
	}
	fout << "\n";
	fout << "Probability for " << i_String << ", ";
	for (int i = 0; i < 10; i++)
	{
		fout << i_inputCounter[i] << ", ";
	}
	fout << "\n" << "\n";
	fout.close();
}
#pragma once
#include <list>
#include <vector>
using namespace std;
class Graph
{
public:
	int m_V;
	list<int>* m_G; //generate by Ctor
	float m_diam = 0; //generate by Diameter()
	bool m_isConnected = true; // generate by Connectivity
	bool m_isIsolated = false;// generate by IsIsolated
private:
	vector<float> m_distance;//generate by Ctor
	vector<int> m_Pai; //generate by Ctor
	vector<int> m_deg_v; //generate by Ctor
public:
	Graph(int V, double P);
	~Graph();
	void addEdge(int v, int w);
	void Diameter();
	void BFS(int s);
	int MaxDistance();
	void IsIsolated();
	void Threshold1AND3();
	void Threshold2();
	void Connectivity(); //runs BFS(0)
};

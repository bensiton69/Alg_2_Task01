#include "Graph.h"
#include <iostream>
#include <list>
using namespace std;
Graph::Graph(int v, double P)
{
	cout << "V = " << v << ", P = " << P << endl;
	m_V = v;
	m_G = new std::list<int>[m_V];
	m_diam = 0;
	m_deg_v = vector <int>(m_V, 0);
	m_distance = vector <float>(m_V, INFINITY);
	m_Pai = vector<int>(m_V, NULL);
	double q;
	if (P == 0)
		return;
	for (int i = 0; i < m_V; i++)
	{
		for (int j = i + 1; j < m_V; j++)
		{
			q = (double)rand() / RAND_MAX;
			if (q < P) //create edge
			{
				addEdge(i, j);
			}
		}
	}
}
Graph::~Graph()
{
	delete[] m_G;
}
void Graph::addEdge(int v, int w)
{
	
	m_G[v].push_back(w);
	m_G[w].push_back(v);
	m_deg_v[v]++;
	m_deg_v[w]++;
}
void Graph::Diameter()
{
	float diam = 0;
	Connectivity();//runs BFS(0)
	if (m_isConnected == false)	// g is not connected
	{
		m_diam = INFINITY;
		return;
	}
	int last_ver = MaxDistance(); //m_distance
	if (diam < m_distance[last_ver])
		diam = m_distance[last_ver];
	for (int i = 1; i < m_V; i++)
	{
		BFS(i);
		last_ver = MaxDistance(); //m_distance
		if (diam < m_distance[last_ver])
			diam = m_distance[last_ver];
	}
	m_diam = diam;
}
void Graph::BFS(int s)
{
	bool* visited = new bool[m_V];
	for (int i = 0; i < m_V; i++)
		visited[i] = false;
	m_distance[s] = 0;
	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	std::list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		queue.pop_front();

		for (i = m_G[s].begin(); i != m_G[s].end(); ++i)
		{
			if (!visited[*i])
			{
				m_Pai[*i] = s;
				if (m_distance[m_Pai[*i]] + 1 < m_distance[*i])
					m_distance[*i] = m_distance[m_Pai[*i]] + 1;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	delete[] visited;
}
int Graph::MaxDistance()
{
	int index = 0;
	float max = m_distance[0];
	for (int i = 1; i < m_V; i++)
		if (max < m_distance[i])
		{
			max = m_distance[i];
			index = i;
		}
	return index;
}
void Graph::IsIsolated()
{
	for (int i = 0; i < m_V; i++)
	{
		if (m_deg_v[i] == 0)
		{
			m_isIsolated = true;
		}
	}
}
void Graph::Threshold1AND3()
{
	IsIsolated();
	if (m_isIsolated) //If there is a isolated v, then G is not connected
		m_isConnected = false;
	else
		Connectivity();
}
void Graph::Threshold2()
{
	Diameter();
}
void Graph::Connectivity()
{
	BFS(0);
	for (int i = 0; i < m_V; i++)
		if (m_distance[i] == INFINITY)
		{
			m_isConnected = false;
			return;
		}
}

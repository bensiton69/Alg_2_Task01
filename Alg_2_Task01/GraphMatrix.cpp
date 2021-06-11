#include "GraphMatrix.h"

GraphMatrix::GraphMatrix(int n, double p):n(n+1),p(p)
{
	n++;
	matrix.resize(n);
	for (int i = 0; i < n; ++i)
	{
		matrix[i].resize(n);
	}
	for (int i = 0; i < n; i++)
		matrix[0][i] = matrix[i][0] = i;
	int j = 0;
	int jToCopy = j; // indicate the next column to check
	for (int i = 1; i < n; i++)
	{
		jToCopy = j++;
		for (j ; j < n; j++)
		{
			if (i == j) continue;
			double q = (double)rand() / RAND_MAX;
			if (q < p)
				matrix[i][j] = matrix[j][i] = 1;
		}
		j = jToCopy;
	}
}

GraphMatrix::GraphMatrix(int n):n(n),p(0.23)
{
	vector <int> deg_V(n, 0);
	int degCounter;
	matrix.resize(n);
	for (int i = 0; i < n; ++i)
	{
		matrix[i].resize(n);
	}
	int j = -1;
	double q;
	int jToCopy = j; // indicate the next column to check
	for (int i = 0; i < n; i++)
	{
		degCounter = 0;
		jToCopy = j++;
		for (j; j < n; j++)
		{
			if (i == j) continue;
			q = (double)rand() / RAND_MAX;
			if (q < p) //create edge
			{
				matrix[i][j] = matrix[j][i] = 1;
				deg_V[i]++;
				deg_V[j]++;
			}
		}
		j = jToCopy;
		//deg_V[i] = degCounter;
	}
	GraphMatrix::deg_V = deg_V;
	
	
}

int GraphMatrix::Diameter()
{
	return 0;
}

ostream& operator<<(ostream& output, const GraphMatrix& i_GraphMatrix)
{
	int n =i_GraphMatrix.n;
	double p = i_GraphMatrix.p;
	vector<int> deg_V = i_GraphMatrix.deg_V;
	cout << "   ";
	for (int i = 0; i < n; i++)
		cout << i << "  ";
	cout << endl;
	for(int i =0;i<n;i++)
	{
		cout << i  << "  ";
		for(int j=0;j<n;j++)
		{
			cout << i_GraphMatrix.matrix[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i < deg_V.size(); i++)
		cout << "deg of vertex " << i << " is " << deg_V[i] << endl;
		//if (deg_V[i] == 0)
		//	cout << "vertex " << i << " is isolated." << endl;
	return output;
}

void GraphMatrix::BFS(int start)
{
	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
	vector<bool> visited(n, false);
	vector<int> q;
	bool isConnected = false;
	q.push_back(start);

	// Set source as visited
	visited[start] = true;

	while (!q.empty()) {
		int vis = q[0];

		// Print the current node
		cout << vis << " ";
		q.erase(q.begin());

		// For every adjacent vertex to the current vertex
		for (int i = 0; i < n; i++) {
			if (matrix[vis][i] == 1 && (!visited[i])) {

				// Push the adjacent node to the queue
				q.push_back(i);

				// Set
				visited[i] = true;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < visited.size(); i++)
	{
		if (visited[i] == false)
		{
			cout << "graph is not connected " << endl;
			isConnected = false;
		}
	}
	
}
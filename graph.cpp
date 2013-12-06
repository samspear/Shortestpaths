#include "graph.h"

using namespace std;

//public

graph::graph(){}

void graph::addEdge(int vertex, int edge)
{
	map<int, vector<int> >::iterator it = adjList.find(vertex);
	if (it == adjList.end())
	{
		vector<int> edges;
		edges.push_back(edge);
		adjList.insert(pair<int, vector<int> > (vertex, edges));
	}
	else
	{
		it->second.push_back(edge);
	}
}

void graph::dump()
{
	for (map<int, vector<int> >::iterator it_v = adjList.begin(); it_v != adjList.end(); ++it_v)
	{
		cout << it_v->first << " | ";
		for(vector<int>::iterator it_e = it_v->second.begin(); it_e != it_v->second.end(); ++it_e)
		{
			cout << *it_e << " ";
		}
		cout << endl;
	}
	cout << "Size of adjacency list " << adjList.size() << endl;
}

//private

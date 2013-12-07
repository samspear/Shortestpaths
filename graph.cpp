#include "graph.h"

using namespace std;

//public

graph::graph(){}

void graph::setDirected()
{
	directed = true;
}

void graph::setUndirected()
{
	directed = false;	
}

void graph::addEdge(char vertex, char edge, int weight)
{
	map<char, vector<pair<char, int> > >::iterator it = adjList.find(vertex);
	if (it == adjList.end())
	{
		vector<pair<char, int> > edges;
		edges.push_back(make_pair(edge, weight));
		adjList.insert(make_pair(vertex, edges));
	}
	else
	{
		it->second.push_back(make_pair(edge, weight));
	}
}

bool graph::checkEdge(char edge)
{
	return (adjList.find(edge) != adjList.end());
}

void graph::dump()
{
	for (map<char, vector<pair<char, int > > >::iterator it_v = adjList.begin(); it_v != adjList.end(); ++it_v)
	{
		cout << it_v->first << " | ";
		for(vector<pair<char, int> >::iterator it_e = it_v->second.begin(); it_e != it_v->second.end(); ++it_e)
		{
			cout << it_e->first << " ";
		}
		cout << endl;
	}
	cout << "Size of adjacency list " << adjList.size() << endl;
}

void graph::dijkstra(char source)
{
	ofstream outfile;
	outfile.open("out.txt");
	outfile << "Dijkstra\n";
	outfile << "Source : " << source << endl;
	outfile << "End Dijstra\n\n";
	outfile.close();
}

void graph::srpa(char source, int k)
{
	ofstream outfile;
	outfile.open("out.txt", ios::ate | ios:: app);
	outfile << "Shortest Reliable Paths Algorithm\n";
	outfile << "Source : " << source << endl;
	outfile << "Integer k : " << k << endl;
	outfile << "End Shortest Reliable Paths Algorithm";
	outfile.close();
}

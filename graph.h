#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class graph
{
	public:
		graph();
		void setDirected();
		void setUndirected();	
		void addEdge(char vertex, char edge, int weight);
		bool checkEdge(char vertex);
		void dump();
		void dijkstra(char source);
		void srpa(char source, int k);
	private:
		map<char, vector<pair<char, int> > > adjList;
		bool directed;
};

#endif

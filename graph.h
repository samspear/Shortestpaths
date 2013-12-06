#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

class graph
{
	public:
		graph();
		void addNode(int vertex);
		void addEdge(int vertex, int edge);
		void dump();
	private:
		map<int, vector<int> > adjList;
		stack<int> S, P;
		map<int, int> preorder;
		int counter;
};

#endif

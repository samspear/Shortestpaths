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
	// Adjacency List
	map<char, vector<pair<char, int> > >::iterator it_v = adjList.find(vertex);
	if (it_v == adjList.end())
	{
		vector<pair<char, int> > edges;
		edges.push_back(make_pair(edge, weight));
		adjList.insert(make_pair(vertex, edges));
	}
	else
	{
		it_v->second.push_back(make_pair(edge, weight));
	}
	if(!directed)
	{
		map<char, vector<pair<char, int> > >::iterator it_e = adjList.find(edge);
		if (it_e == adjList.end())
		{
			vector<pair<char, int> > edges;
			edges.push_back(make_pair(vertex, weight));
			adjList.insert(make_pair(edge, edges));
		}
		else
		{
			it_e->second.push_back(make_pair(vertex, weight));
		}
	}
}

bool graph::checkEdge(char edge)
{
	return (adjList.find(edge) != adjList.end());
}

list<char> graph::getVertexList()
{
	list<char> vList;
	for (map<char, vector<pair<char, int > > >::iterator it_v = adjList.begin(); it_v != adjList.end(); ++it_v)
	{
		vList.push_front(it_v->first);
		for(vector<pair<char, int> >::iterator it_e = it_v->second.begin(); it_e != it_v->second.end(); ++it_e)
		{
			vList.push_front(it_e->first);
		}
	}
	vList.sort();
	vList.unique();
	return vList;
}

void graph::dump()
{
	for (map<char, vector<pair<char, int > > >::iterator it_v = adjList.begin(); it_v != adjList.end(); ++it_v)
	{
		cout << it_v->first << " | ";
		for(vector<pair<char, int> >::iterator it_e = it_v->second.begin(); it_e != it_v->second.end(); ++it_e)
		{
			cout << it_e->first << "-" << it_e->second << " ";
		}
		cout << endl;
	}
	cout << "Size of adjacency list " << adjList.size() << endl;
}

void graph::dijkstra(char source)
{
	// Initialize
	list<char> vList = getVertexList();
	priority_queue<pair<char, int>, vector<pair<char, int> >, compare> pq;
	map<char, int> distance;
	int infinity = numeric_limits<int>::max();
	for(list<char>::iterator it = vList.begin(); it != vList.end(); ++it)
	{
		if(*it == source)
		{
			distance.insert(make_pair(*it, 0));
		}
		else
		{
			distance.insert(make_pair(*it, infinity)); // Infinity 
		}
		pq.push(make_pair(*it, distance.at(*it)));	
	}
	while(!pq.empty())
	{
		char currentVertex = pq.top().first;
		pq.pop();
		map<char, vector<pair<char, int> > >::iterator it_v = adjList.find(currentVertex);
		if(it_v != adjList.end())
		{
			for(vector<pair<char, int> >::iterator it_e = it_v->second.begin(); it_e != it_v->second.end(); ++it_e)
			{
				if(distance.at(currentVertex) != infinity)
				{
					int alt = distance.at(currentVertex) + it_e->second;
					if(alt < distance.at(it_e->first))
					{
						distance.at(it_e->first) = alt;
						priority_queue<pair<char, int>, vector<pair<char, int> >, compare> temp_pq;
						while(!pq.empty())
						{
							if(pq.top().first == it_e->first)
							{
								temp_pq.push(make_pair(it_e->first, alt));
								pq.pop();
							}
							else
							{
								temp_pq.push(pq.top());
								pq.pop();
							}
						}
						swap(pq, temp_pq);
					}
				}
			}
		}
	}
	// Output
	ofstream outfile;
	outfile.open("out.txt");
	outfile << "Dijkstra\n";
	outfile << "Source : " << source << endl;
	for (list<char>::iterator it = vList.begin(); it != vList.end(); ++it)
	{
		outfile << "Node " << *it << " : ";
		if (distance.at(*it) == infinity)
		{
			outfile << "Undefined" << endl;
		}
		else
		{
			outfile << distance.at(*it) << endl;
		}
	}
	outfile << "End Dijstra\n\n";
	outfile.close();
}

void graph::srpa(char source, int k)
{
	// Initialize
	list<char> vList = getVertexList();
	priority_queue<pair<char, int>, vector<pair<char, int> >, compare> pq;
	map<char, int> distance;
	int infinity = numeric_limits<int>::max();
	for(list<char>::iterator it = vList.begin(); it != vList.end(); ++it)
	{
		if(*it == source)
		{
			distance.insert(make_pair(*it, 0));
		}
		else
		{
			distance.insert(make_pair(*it, infinity)); // Infinity 
		}
		pq.push(make_pair(*it, distance.at(*it)));	
	}
	while(!pq.empty())
	{
		char currentVertex = pq.top().first;
		pq.pop();
		map<char, vector<pair<char, int> > >::iterator it_v = adjList.find(currentVertex);
		if(it_v != adjList.end())
		{
			for(vector<pair<char, int> >::iterator it_e = it_v->second.begin(); it_e != it_v->second.end(); ++it_e)
			{
				if(distance.at(currentVertex) != infinity)
				{
					int alt = distance.at(currentVertex) + it_e->second;
					if(alt < distance.at(it_e->first))
					{
						distance.at(it_e->first) = alt;
						priority_queue<pair<char, int>, vector<pair<char, int> >, compare> temp_pq;
						while(!pq.empty())
						{
							if(pq.top().first == it_e->first)
							{
								temp_pq.push(make_pair(it_e->first, alt));
								pq.pop();
							}
							else
							{
								temp_pq.push(pq.top());
								pq.pop();
							}
						}
						swap(pq, temp_pq);
					}
				}
			}
		}
	}
	// Output
	ofstream outfile;
	outfile.open("out.txt", ios::ate | ios:: app);
	outfile << "Shortest Reliable Paths Algorithm\n";
	outfile << "Source : " << source << endl;
	outfile << "Integer k : " << k << endl;
	for (list<char>::iterator it = vList.begin(); it != vList.end(); ++it)
	{
		outfile << "Node " << *it << " : ";
		if (distance.at(*it) == infinity)
		{
			outfile << "Undefined" << endl;
		}
		else
		{
			outfile << distance.at(*it) << endl;
		}
	}
	outfile << "End Shortest Reliable Paths Algorithm";
	outfile.close();
}

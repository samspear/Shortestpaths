#include "graph.h"
#include <fstream>
#include <sstream>
using namespace std;

graph myGraph;
string line;
stringstream ss;
char vertex, edge;
int weight, source, k;

int main(int argc, char* argv[])
{
	// Open File

	if(argc != 2)
	{
		cout << "Usage: Graph <filename>\n";
		return 0;	
	}
	ifstream infile;
	infile.open(argv[1]);
	if(!infile.good())
	{
		cout << "Error in opening file " << argv[1] << endl;
		return 0;
	}

	// Check for comments and set graph type

	while(getline(infile, line))
	{
		ss.str(line);
		if (ss.peek() == '#') // Check for comments
		{
			ss.clear();
		}
		else if (ss.peek() == 'D')
		{
			myGraph.setDirected();
			ss.clear();
			break;
		}
		else if (ss.peek() == 'U')
		{
			myGraph.setUndirected();
			ss.clear();
			break;
		}
		else
		{
			cout << "ERROR: You must specify a graph type\n";
			return 0;
		}
	}

	// Create Adjacency and Node Lists

	while(!getline(infile, line).eof())
	{
		ss.str(line);
		ss >> vertex;
		ss >> edge;
		ss >> weight;
		if (ss.fail())
		{
			cout << "ERROR: Invalid Input!\n";
			return 0;
		}
		myGraph.addEdge(vertex, edge, weight);		
		ss.clear();
	}

	// Dijkstra's Algorithm

	cout << "Dijstra\n";
	cout << "Source : ";
	source = cin.get();
	myGraph.dijkstra(source);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Shortest Reliable Paths Algorithm

	cout << "Shortest Reliable Paths Algorithm\n";
	cout << "Source : ";
	source = cin.get();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Integer k : ";
	k = cin.get();
	myGraph.srpa(source, k);

	return 1;
}

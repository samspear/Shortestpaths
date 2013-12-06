#include "graph.h"
#include <fstream>
#include <sstream>
using namespace std;

graph myGraph;
string line;
stringstream ss;
int vertex, edge;

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

	// Create Adjacency and Node Lists

	while(!getline(infile, line).eof())
	{
		ss.str(line);
		if (ss.peek() != '#') // Check for comments
		{
			ss >> vertex;
			ss >> edge;
			if (ss.fail())
			{
				cout << "ERROR: Invalid Input!\n";
				return 0;
			}
			myGraph.addEdge(vertex, edge);
		}
		ss.clear();
	}
	return 1;
}

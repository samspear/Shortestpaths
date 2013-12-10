#include "compare.h"

using namespace std;

bool compare::operator()(pair<char, int> comp_1, pair<char, int> comp_2)
{
	return (comp_1.second > comp_2.second);	
}


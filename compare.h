#ifndef COMPARE_H
#define COMPARE_H
#include <queue>

using namespace std;

class compare
{
        public:
		bool operator()(pair<char, int> comp_1, pair<char, int> comp_2);
};

#endif


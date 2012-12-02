//
//	GraphAlgs.cpp
//
//	Created by Jake Gregg on 12/02/2012
//

#include "GraphAlgs.h"
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

/// Simple recursive function to calculate factorials based on the 
/// number of nodes passed in (n)
int GraphAlgs::factorial(int n) {
	if (n == 1)
		return 1;
	else 
		return n * factorial(n-1);
}

pair<vector<NodeID>, EdgeWeight> TSP (Graph* G) {
	vector<NodeID> curr_path;
	EdgeWeight dist;
	vector<NodeID> best_path;
	EdgeWeight best_dist;
	list<NWPair> openList;
}

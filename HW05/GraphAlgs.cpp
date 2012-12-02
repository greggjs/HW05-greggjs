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
int factorial(int n) {
	if (n == 1)
		return 1;
	else 
		return n * factorial(n-1);
}

pair<vector<NodeID>, EdgeWeight> TSP (Graph* G) {
	
	/// Vars needed for TSP
	vector<NodeID> curr;
	EdgeWeight dist = 0;
	vector<NodeID> best_path;
	EdgeWeight best_dist = DBL_MAX;
	list<NWPair> openList;
	list<NWPair>::iterator it;
	int n;

	/// 
	for (int i = 0; i < G->size(); i++)
		curr.push_back(i);
	n = G->size();

	for (int i = 0; i < factorial(n-1); i++) {
		dist = G->weight(0, curr[0]);
		for (int j = 0; j < n; j++) {
			if (dist > best_dist)
				break;
			else {
				if (j == n-2)
					dist += G->weight(curr.at(0), curr.at(1));
				else 
					dist += G->weight(curr.at(j+1), curr.at(j));
			}
		}

		if (dist < best_dist) {
			best_path = curr;
			best_dist = dist;
		}

		/// Got this idea from my roommate Brian. Great function call to use for
		/// getting the next permutation.
		next_permutation(curr.begin(), curr.end());
	}
	best_path.insert(best_path.begin(), 0);
	pair<vector<NodeID>, EdgeWeight> res (best_path, best_dist);
	return res;
}

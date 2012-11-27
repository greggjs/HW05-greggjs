//
//	ListGraph.cpp
//
//	Created by Jake Gregg 11/27/2012
//	
//

#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int numNodes) {
	edgeList.resize(numNodes);
	num_edges = 0;
	/// this->num_edges = numNodes * (numNodes - 1) /2;
}

ListGraph::~ListGraph() {}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	EList::const_iterator it;
	for (it=edgeList[u].begin(); it != edgeList[u].end(); it++) {
		NWPair edge = *it; // not a pointer, just returns edge that it is at
		if (edge.first == v)
			return edge.second;
	}

	return 0.0;
}

list<NWPair> ListGraph::getAdj(NodeID u) const {
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const {
	return edgeList[u].size();
}

unsigned ListGraph::size() const {

}

unsigned ListGraph::numEdges() const {

}


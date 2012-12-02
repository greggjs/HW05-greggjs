//
//	ListGraph.cpp
//
//	Created by Jake Gregg 11/27/2012
//	
//

#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int numNodes) {
	
	/// Dr. Brinkman's constructor shown using the resize() function
	edgeList.resize(numNodes);
	num_edges = 0;
	
}

ListGraph::~ListGraph() {
	for (int i = 0; i < this->edgeList.size(); i++) 
		edgeList.pop_back();
}

void ListGraph::addEdge(NodeID u, NodeID v, Edgeweight weight) {
	edgeList.at(u).push_back(NWPair(v, weight));
	edgeList.at(v).push_back(NWPair(u, weight));
}

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
	return edgeList.at(u);
}

unsigned ListGraph::degree(NodeID u) const {
	return (edgeList.at(u)).size();
}

unsigned ListGraph::size() const {
	return edgeList.size();
}

unsigned ListGraph::numEdges() const {
	int size=0;

	EList::const_iterator it;

	for (int i = 0; i < edgeList.size(); i++) {
		for (it = ((edgeList.at(i).begin()); it != (edgeList.at(i)).end); it++) {
			if ((*iter).first > i)
				size++;
		}
	}

	return size;
}


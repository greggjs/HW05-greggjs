//
//	ListGraph.cpp
//
//	Created by Jake Gregg 11/27/2012
//

#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int numNodes) {
	edgeList.resize(numNodes);
	num_edges = 0;
	/// this->num_edges = numNodes * (numNodes - 1) /2;
}

ListGraph::~ListGraph() {
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {

}

list<NWPair> ListGraph::getAdj(NodeID u) const {

}

unsigned ListGraph::degree(NodeID u) const {

}

unsigned ListGraph::size() const {

}

unsigned ListGraph::numEdges() const {

}


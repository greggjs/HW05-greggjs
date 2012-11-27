//
//	ListGraph.cpp
//
//	Created by Jake Gregg 11/27/2012
//

#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int num_nodes) {
	this->num_edges = num_nodes * (num_nodes - 1) /2;
}

ListGraph::~ListGraph() {
	delete &edgeList;
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


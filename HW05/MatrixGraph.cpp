//
//	MatrixGraph.cpp
//
//	Create by Jake Gregg 11/26/2012
//

#include "MatrixGraph.h"

using namespace std;

MatrixGraph::MatrixGraph(unsigned int num_nodes) {
	num_edges = 0;

	for (int i = 0; i < num_nodes; i++) {
		M.push_back(*(new vector<EdgeWeight>()));
		for (int j = 0; j < num_nodes; j++)
			M.at(i).push_back(0);
	}
}

MatrixGraph::~MatrixGraph() {
	for(int i = 0; i < M.size(); i++){
		M.pop_back();
	}
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	(M.at(u)).at(v) = weight;
	(M.at(v)).at(u) = weight;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return (M.at(u)).at(v);
}

list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	list<NWPair>* near = new list<NWPair>;

	for (int i = 0; i < (M.at(u)).size(); i++) {
		NWPair curr (i, (M.at(u)).at(i));
		if (curr.second != 0)
			near->push_back(curr);
	}
	return *near;
}

unsigned MatrixGraph::degree(NodeID u) const {
	int degree = 0;
	for (int i = 0; i < (M.at(u)).size(); i++) {
		if ((M.at(u)).at(i) != 0)
			degree++;
	}
	return degree;
}

unsigned MatrixGraph::size() const {
	return M.size();
}

unsigned MatrixGraph::numEdges() const {
	unsigned total = 0;
	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M.at(i).size(); j++) {
			if (M.at(i).at(j) != 0)
				total++;
		}
	}
	return total;
}
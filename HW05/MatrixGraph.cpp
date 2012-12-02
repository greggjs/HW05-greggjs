//
//	MatrixGraph.cpp
//
//	Create by Jake Gregg 11/26/2012
//

#include "MatrixGraph.h"

using namespace std;

MatrixGraph::MatrixGraph(unsigned int num_nodes) {
	this->num_edges = 0;

	for (int i = 0; i < num_nodes; i++) {
		M.push_back(*(new vector<EdgeWeight>()));
		for (int j = 0; j < num_nodes; j++)
			this->M.at(i).push_back(0);
	}
}

MatrixGraph::~MatrixGraph() {
	for(int i = 0; i < M.size(); i++){
		(this->M).pop_back();
	}
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	((this->M).at(u)).at(v) = weight;
	((this->M).at(v)).at(u) = weight;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return ((this->M).at(u)).at(v);
}

list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	list<NWPair>* near = new list<NWPair>;

	for (int i = 0; i < (M.at(u)).size(); i++) {
		NWPair curr (i, ((this->M).at(u)).at(i));
		if (curr.second != 0)
			near->push_back(curr);
	}
	return *near;
}

unsigned MatrixGraph::degree(NodeID u) const {
	int degree = 0;
	for (int i = 0; i < (M.at(u)).size(); i++) {
		if (((this->M).at(u)).at(i) != 0)
			degree++;
	}
	return degree;
}

unsigned MatrixGraph::size() const {
	return (this->M).size();
}

unsigned MatrixGraph::numEdges() const {
	unsigned total = 0;
	for (int i = 0; i < (this->M).size(); i++) {
		for (int j = 0; j < (this->M).at(i).size(); j++) {
			if ((this->M).at(i).at(j) != 0)
				total++;
		}
	}
	return total;
}
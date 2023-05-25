#ifndef PROJECT2GRAPHS_EXTRAGRAPH_H
#define PROJECT2GRAPHS_EXTRAGRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "ExtraNodes.h"
#include "ExtraVertexEdge.h"
#include <unordered_set>
#include <unordered_map>

///This class contains the implementation of the graph class and all related functions.

class ExtraGraph {
public:
    ~ExtraGraph();
    ExtraGraph()=default;

    Vertex4 *findVertex(const int &id) const;

    bool addVertex(const int &id);

    bool addEdge(const int &sourc, const int &dest, const float &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const float &distancia);

    int getNumVertex() const;

    unordered_map<int,Vertex4 *> getVertexSet() const;

    double calculateNodeDistance(int node1ID, int node2ID);

    void primMST(vector<Edge4*>& mst);

    void preorderTraversal(const vector<Edge4*>& mst, Vertex4* node, vector<bool>& visited,vector<int>& preorder);

    void findMinMSTAndPreorderTraversal(vector<int>& preorder);
protected:
    unordered_map<int,Vertex4 *> vertexSet;    // vertex set

    double ** distMatrix4 = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix4 = nullptr;   // path matrix for Floyd-Warshall

    int findVertexIdx(const int &id) const;

};

class CompareWeight4 {
public:
    bool operator()(const Edge4* e1, const Edge4* e2) {
        return e1->getDistancia() > e2->getDistancia();
    }
};


#endif //PROJECT2GRAPHS_EXTRAGRAPH_H

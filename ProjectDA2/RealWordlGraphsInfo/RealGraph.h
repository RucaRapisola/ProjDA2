#ifndef PROJECT2GRAPHS_REALGRAPH_H
#define PROJECT2GRAPHS_REALGRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <string>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "RealVertexEdge.h"
#include <unordered_map>
using namespace std;

///This class contains the implementation of the graph class and all related functions.

class RealGraph {
public:
    ///Destructor for the graph class.
    ~RealGraph();

    Vertex3 *findVertex(const int &id) const;

    bool addVertex(const int &id, const double &longitude, const double &latitude);

    bool addEdge(const int &sourc, const int &dest, const float &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const float &distancia);

    int getNumVertex() const;

    unordered_map<int,Vertex3 *> getVertexSet() const;

    bool areTheyConnected(int nodesID1, int nodesID2);

    double calculateNodeDistance( int node1ID, int node2ID);

    void preorderTraversal(const vector<Edge3*>& mst, Vertex3* node, vector<bool>& visited,vector<int>&preorder);

    void primMST(vector<Edge3*>& mst);

    void findMinMSTAndPreorderTraversal(vector<int>& preorder) ;

protected:
    unordered_map<int,Vertex3*> vertexSet;    // vertex set

    double ** distMatrix3 = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix3 = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;
};

class CompareWeight3 {
public:
    bool operator()(const Edge3* e1, const Edge3* e2) {
        return e1->getDistancia() > e2->getDistancia();
    }
};



#endif //PROJECT2GRAPHS_REALGRAPH_H

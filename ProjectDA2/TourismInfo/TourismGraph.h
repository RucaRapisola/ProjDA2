#ifndef PROJECT2GRAPHS_TOURISMGRAPH_H
#define PROJECT2GRAPHS_TOURISMGRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "TourismNodes.h"
#include "TourismVertexEdge.h"
#include <unordered_set>

///This class contains the implementation of the graph class and all related functions.

class TourismGraph {
public:

    TourismGraph(TourismGraph &copiar){
        this->vertexSet = copiar.vertexSet;
        this->distMatrix = copiar.distMatrix;
        this->pathMatrix = copiar.pathMatrix;
    }

    ~TourismGraph();
    TourismGraph()=default;

    Vertex *findVertex(const int &id) const;

    bool addVertex(const int &id);

    bool addEdge(const int &sourc, const int &dest, const int &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const int &distancia);

    int getNumVertex() const;

    vector<Vertex *> getVertexSet() const;

    double calculateNodeDistance(int node1ID, int node2ID);

    double backtrack(Vertex *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex *start_vertex,std::vector<int> &min_path, std::vector<int> &current_path);

    void primMST(vector<Edge*>& mst);

    void preorderTraversal(const vector<Edge*>& mst, Vertex* node, vector<bool>& visited,vector<int>& preorder);

    void findMinMSTAndPreorderTraversal(vector<int>& preorder);

protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;

    };

class CompareWeight2 {
public:
    bool operator()(const Edge* e1, const Edge* e2) {
        return e1->getDistancia() > e2->getDistancia();
    }
};


#endif //PROJECT2GRAPHS_TOURISMGRAPH_H

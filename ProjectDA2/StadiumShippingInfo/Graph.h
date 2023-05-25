#ifndef PROJECT2GRAPHS_GRAPH_H
#define PROJECT2GRAPHS_GRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "Nodes.h"
#include "VertexEdge.h"
#include <unordered_set>

///This class contains the implementation of the graph class and all related functions.

class Graph {
public:

    Graph(Graph &copiar){
        this->vertexSet = copiar.vertexSet;
        this->distMatrix2 = copiar.distMatrix2;
        this->pathMatrix2 = copiar.pathMatrix2;
    }

    ~Graph();
    Graph()=default;

    Vertex2 *findVertex(const int &id) const;

    bool addVertex(const int &id);

    bool addEdge(const int &sourc, const int &dest, const float &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const float &distancia);

    int getNumVertex() const;

    vector<Vertex2 *> getVertexSet() const;

    double calculateNodeDistance(int node1ID, int node2ID);

    double backtrack(Vertex2 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex2 *start_vertex,std::vector<int> &min_path, std::vector<int> &current_path);

    void preorderTraversal(const vector<Edge2*>& mst, Vertex2* node, vector<bool>& visited,vector<int>&preorder);

    void primMST(vector<Edge2*>& mst);

    void findMinMSTAndPreorderTraversal(vector<int>& preorder) ;


protected:
    std::vector<Vertex2 *> vertexSet;    // vertex set

    double ** distMatrix2 = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix2 = nullptr;   // path matrix for Floyd-Warshall

    int findVertexIdx(const int &id) const;

};

class CompareWeight {
public:
    bool operator()(const Edge2* e1, const Edge2* e2) {
        return e1->getDistancia() > e2->getDistancia();
    }
};


#endif //PROJECT2GRAPHS_GRAPH_H

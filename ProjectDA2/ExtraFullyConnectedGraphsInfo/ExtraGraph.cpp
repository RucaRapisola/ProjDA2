#include "ExtraGraph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int ExtraGraph::getNumVertex() const {
    return vertexSet.size();
}

std::unordered_map<int,Vertex4 *> ExtraGraph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex4 * ExtraGraph::findVertex(const int &id) const {
    auto it = vertexSet.find(id);
    if(it!= vertexSet.end())
        return it->second;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int ExtraGraph::findVertexIdx(const int &id) const {
    auto it = vertexSet.find(id);
    if(it!= vertexSet.end())
        return it->first;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool ExtraGraph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.insert(make_pair(id,new Vertex4(id)));
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool ExtraGraph::addEdge(const int &sourc, const int &dest, const float &distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, distancia);
    return true;
}

bool ExtraGraph::addBidirectionalEdge(const int &sourc, const int &dest,const float& distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2,distancia);
    auto e2 = v2->addEdge(v1, distancia);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

void deleteMatrix4(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix4(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

ExtraGraph::~ExtraGraph() {
    deleteMatrix4(distMatrix4, vertexSet.size());
    deleteMatrix4(pathMatrix4, vertexSet.size());
}

double ExtraGraph::calculateNodeDistance(int node1ID, int node2ID) {
    Vertex4* node1 = this->findVertex(node1ID);
    Vertex4* node2 = this->findVertex(node2ID);

    for (auto edge :node1->getAdj()){
        if(edge->getDest() == node2){
            return edge->getDistancia();
        }
    }
    return 0.0;
}
//4.2
void ExtraGraph::primMST(vector<Edge4*>& mst) {
    int V = this->getNumVertex();

    // Priority queue to store edges with minimum weight
    priority_queue<Edge4*, vector<Edge4*>, CompareWeight4> pq;

    // Start with vertex 0 as the source
    Vertex4* source = this->findVertex(0);

    // Create a vector to track visited vertices
    vector<bool> visited(V, false);

    // Add the edges connected to the source vertex to the priority queue
    for (const auto& edge : source->getAdj()) {
        if (edge->getOrig() == source)
            pq.push(edge);
    }

    visited[source->getId()] = true;

    while (!pq.empty()) {
        Edge4* edge = pq.top();
        pq.pop();

        Vertex4* u = edge->getOrig();
        Vertex4* v = edge->getDest();

        if (visited[v->getId()])
            continue;

        visited[v->getId()] = true;

        mst.push_back(edge);

        for (const auto& neighbor : this->vertexSet) {
            if (neighbor.second == v) {
                for (auto edge : neighbor.second->getAdj()){
                    if(!visited[edge->getDest()->getId()]){
                        pq.push(edge);
                    }
                }
            }
        }
    }
}

// Function to perform preorder traversal of MST
void ExtraGraph::preorderTraversal(const vector<Edge4*>& mst, Vertex4* node, vector<bool>& visited,vector<int>& preorder) {
    visited[node->getId()] = true;
    cout << node->getId() << " ";
    preorder.push_back(node->getId());

    for (const auto& edge : mst) {
        if (edge->getOrig() == node && !visited[edge->getDest()->getId()])
            preorderTraversal(mst, edge->getDest(), visited,preorder);
    }
}

// Function to find the minimum spanning tree and perform preorder traversal
void ExtraGraph::findMinMSTAndPreorderTraversal(vector<int>& preorder) {
    vector<Edge4*> mst;
    primMST( mst);

    cout << "Minimum Spanning Tree (MST) connections:" << endl;
    for (const auto& edge : mst) {
        cout << edge->getOrig()->getId() << " -- " << edge->getDest()->getId() << " (Distância entre os dois nodes: " << edge->getDistancia() << ")" << endl;
    }

    cout << "Preorder Traversal of MST (Left to Right): ";
    vector<bool> visited(this->getNumVertex(), false);
    preorderTraversal(mst, mst[0]->getOrig(), visited,preorder);
    cout << endl;
}
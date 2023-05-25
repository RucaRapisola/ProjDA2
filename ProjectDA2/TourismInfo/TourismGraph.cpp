#include "TourismGraph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int TourismGraph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> TourismGraph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * TourismGraph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int TourismGraph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool TourismGraph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id));
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool TourismGraph::addEdge(const int &sourc, const int &dest, const int &distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, distancia);
    return true;
}

bool TourismGraph::addBidirectionalEdge(const int &sourc, const int &dest,const int& distancia) {
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

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

TourismGraph::~TourismGraph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}
double TourismGraph::calculateNodeDistance(int node1ID, int node2ID) {
    Vertex* node1 = this->findVertex(node1ID);
    Vertex* node2 = this->findVertex(node2ID);

    for (auto edge :node1->getAdj()){
        if(edge->getDest() == node2){
            return edge->getDistancia();
        }
    }
    return 0.0;
}

double TourismGraph::backtrack(Vertex *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex *start_vertex, std::vector<int> &min_path, std::vector<int> &current_path) {
    visited[current_vertex->getId()] = true;
    current_path.push_back(current_vertex->getId());
    count++;

    if (count == visited.size()) {
        for (Edge *edge : current_vertex->getAdj()) {
            if (edge->getDest() == start_vertex) {
                double total_distance = distance + edge->getDistancia();
                if (total_distance < min_distance) {
                    min_distance = total_distance;
                    min_path = current_path;
                }
                break;
            }
        }
    } else {
        for (Edge *edge : current_vertex->getAdj()) {
            Vertex *adj_vertex = edge->getDest();
            if (!visited[adj_vertex->getId()]) {
                double new_distance = distance + edge->getDistancia();
                min_distance = backtrack(adj_vertex, visited, count, new_distance, min_distance, start_vertex, min_path, current_path);
            }
        }
    }

    visited[current_vertex->getId()] = false;
    current_path.pop_back();
    count--;

    return min_distance;
}

//4.2
void TourismGraph::primMST(vector<Edge*>& mst) {
    int V = this->getNumVertex();

    // Priority queue to store edges with minimum weight
    priority_queue<Edge*, vector<Edge*>, CompareWeight2> pq;

    // Start with vertex 0 as the source
    Vertex* source = this->findVertex(0);

    // Create a vector to track visited vertices
    vector<bool> visited(V, false);

    // Add the edges connected to the source vertex to the priority queue
    for (const auto& edge : source->getAdj()) {
        if (edge->getOrig() == source)
            pq.push(edge);
    }

    visited[source->getId()] = true;

    while (!pq.empty()) {
        Edge* edge = pq.top();
        pq.pop();

        Vertex* u = edge->getOrig();
        Vertex* v = edge->getDest();

        if (visited[v->getId()])
            continue;

        visited[v->getId()] = true;

        mst.push_back(edge);

        for (const auto& neighbor : this->vertexSet) {
            if (neighbor == v) {
                for (auto edge : neighbor->getAdj()){
                    if(!visited[edge->getDest()->getId()]){
                        pq.push(edge);
                    }
                }
            }
        }
    }
}

// Function to perform preorder traversal of MST
void TourismGraph::preorderTraversal(const vector<Edge*>& mst, Vertex* node, vector<bool>& visited,vector<int>& preorder) {
    visited[node->getId()] = true;
    cout << node->getId() << " -> ";
    preorder.push_back(node->getId());

    for (const auto& edge : mst) {
        if (edge->getOrig() == node && !visited[edge->getDest()->getId()])
            preorderTraversal(mst, edge->getDest(), visited,preorder);
    }
}

// Function to find the minimum spanning tree and perform preorder traversal
void TourismGraph::findMinMSTAndPreorderTraversal(vector<int>& preorder) {
    vector<Edge*> mst;
    primMST( mst);

    cout << "Minimum Spanning Tree (MST) connections:" << endl;
    for (const auto& edge : mst) {
        cout << edge->getOrig()->getId() << " -- " << edge->getDest()->getId() << " (Distância entre os dois nodes: " << edge->getDistancia() << ")" << endl;
    }
    cout << endl;
    cout << "Preorder Traversal of MST (Left to Right): ";
    vector<bool> visited(this->getNumVertex(), false);
    preorderTraversal(mst, mst[0]->getOrig(), visited,preorder);
}

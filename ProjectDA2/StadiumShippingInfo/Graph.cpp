#include "Graph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex2 *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex2 * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex2(id));
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, const float &distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, distancia);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest,const float& distancia) {
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

void deleteMatrix2(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix2(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix2(distMatrix2, vertexSet.size());
    deleteMatrix2(pathMatrix2, vertexSet.size());
}

double Graph::calculateNodeDistance(int node1ID, int node2ID) {
    Vertex2* node1 = this->findVertex(node1ID);
    Vertex2* node2 = this->findVertex(node2ID);

    for (auto edge :node1->getAdj()){
        if(edge->getDest() == node2){
            return edge->getDistancia();
        }
    }
    return 0.0;
}

double Graph::backtrack(Vertex2 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex2 *start_vertex, std::vector<int> &min_path, std::vector<int> &current_path) {
    visited[current_vertex->getId()] = true;
    current_path.push_back(current_vertex->getId());
    count++;

    if (count == visited.size()) {
        for (Edge2 *edge : current_vertex->getAdj()) {
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
        for (Edge2 *edge : current_vertex->getAdj()) {
            Vertex2 *adj_vertex = edge->getDest();
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
void Graph::primMST(vector<Edge2*>& mst) {
    int V = this->getNumVertex();

    // Priority queue to store edges with minimum weight
    priority_queue<Edge2*, vector<Edge2*>, CompareWeight> pq;

    // Start with vertex 0 as the source
    Vertex2* source = this->findVertex(0);

    // Create a vector to track visited vertices
    vector<bool> visited(V, false);

    // Add the edges connected to the source vertex to the priority queue
    for (const auto& edge : source->getAdj()) {
        if (edge->getOrig() == source)
            pq.push(edge);
    }

    visited[source->getId()] = true;

    while (!pq.empty()) {
        Edge2* edge = pq.top();
        pq.pop();

        Vertex2* u = edge->getOrig();
        Vertex2* v = edge->getDest();

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
void Graph::preorderTraversal(const vector<Edge2*>& mst, Vertex2* node, vector<bool>& visited,vector<int>& preorder) {
    visited[node->getId()] = true;
    cout << node->getId() << " -> ";
    preorder.push_back(node->getId());

    for (const auto& edge : mst) {
        if (edge->getOrig() == node && !visited[edge->getDest()->getId()])
            preorderTraversal(mst, edge->getDest(), visited,preorder);
    }
}

// Function to find the minimum spanning tree and perform preorder traversal
void Graph::findMinMSTAndPreorderTraversal(vector<int>& preorder) {
    vector<Edge2*> mst;
    primMST( mst);

    cout << "Minimum Spanning Tree (MST) connections:" << endl;
    for (const auto& edge : mst) {
        cout << edge->getOrig()->getId() << " -- " << edge->getDest()->getId() << " (Distância entre os dois nodes: " << edge->getDistancia() << ")" << endl;
    }

    cout << "Preorder Traversal of MST (Left to Right): ";
    vector<bool> visited(this->getNumVertex(), false);
    preorderTraversal(mst, mst[0]->getOrig(), visited,preorder);
}







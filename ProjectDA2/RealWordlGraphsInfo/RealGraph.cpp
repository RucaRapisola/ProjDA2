#include "RealGraph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
#include "cmath"
using namespace std;

int RealGraph::getNumVertex() const {
    return vertexSet.size();
}

std::unordered_map<int,Vertex3 *> RealGraph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex3 * RealGraph::findVertex(const int &id) const {
    auto it = vertexSet.find(id);
    if(it!= vertexSet.end())
        return it->second;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int RealGraph::findVertexIdx(const int &id) const {
    auto it = vertexSet.find(id);
    if(it!= vertexSet.end())
        return it->first;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool RealGraph::addVertex(const int &id, const double &longitude, const double &latitude) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.insert(make_pair(id,new Vertex3(id,longitude,latitude)));
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool RealGraph::addEdge(const int &sourc, const int &dest, const float &distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, distancia);
    return true;
}

bool RealGraph::addBidirectionalEdge(const int &sourc, const int &dest,const float& distancia) {
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

void deleteMatrix3(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix3(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

RealGraph::~RealGraph() {
    deleteMatrix3(distMatrix3, vertexSet.size());
    deleteMatrix3(pathMatrix3, vertexSet.size());
}

//checking if 2 nodes are connected
bool RealGraph::areTheyConnected(int nodesID1, int nodesID2){
    bool connected= false;
    Vertex3* node1 = this->findVertex(nodesID1);
    Vertex3* node2 = this->findVertex(nodesID2);
    for (auto edge : node1->getAdj()){
        if(edge->getDest() == node2){
            connected = true;
            break;
        }
    }
    return connected;
}

//calculation between two nodes which are not connected
const double EARTH_RADIUS = 6371.0; // Earth's radius in kilometers

double haversineDistance(Vertex3* node1, Vertex3* node2) {
    // Convert latitude and longitude from degrees to radians
    double lat1Rad = node1->getLatitude()* M_PI / 180.0;
    double lon1Rad = node1->getLongitude() * M_PI / 180.0;
    double lat2Rad = node2->getLatitude() * M_PI / 180.0;
    double lon2Rad = node2->getLongitude() * M_PI / 180.0;

    // Calculate differences
    double dLat = lat2Rad - lat1Rad;
    double dLon = lon2Rad - lon1Rad;

    // Apply Haversine formula
    double a = std::sin(dLat / 2.0) * std::sin(dLat / 2.0) + std::cos(lat1Rad) * std::cos(lat2Rad) * std::sin(dLon / 2.0) * std::sin(dLon / 2.0);
    double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

double RealGraph::calculateNodeDistance(int node1ID, int node2ID) {
    Vertex3* node1 = this->findVertex(node1ID);
    Vertex3* node2 = this->findVertex(node2ID);

    if (!this->areTheyConnected(node1ID, node2ID)) {
        double distance = haversineDistance(node1,node2);
        return distance;
    }

    else{
        for (auto edge :node1->getAdj()){
            if(edge->getDest() == node2){
                return edge->getDistancia();
            }
        }
    }
    return 0.0;
}


//4.2

void RealGraph::primMST(vector<Edge3*>& mst) {
    int V = this->getNumVertex();

    // Priority queue to store edges with minimum weight
    priority_queue<Edge3*, vector<Edge3*>, CompareWeight3> pq;

    // Start with vertex 0 as the source
    Vertex3* source = this->findVertex(0);

    // Create a vector to track visited vertices
    vector<bool> visited(V, false);

    // Add the edges connected to the source vertex to the priority queue
    for (const auto& edge : source->getAdj()) {
        if (edge->getOrig() == source)
            pq.push(edge);
    }

    visited[source->getId()] = true;

    while (!pq.empty()) {
        Edge3* edge = pq.top();
        pq.pop();

        Vertex3* u = edge->getOrig();
        Vertex3* v = edge->getDest();

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
void RealGraph::preorderTraversal(const vector<Edge3*>& mst, Vertex3* node, vector<bool>& visited,vector<int>& preorder) {
    visited[node->getId()] = true;
    cout << node->getId() << " ";
    preorder.push_back(node->getId());

    for (const auto& edge : mst) {
        if (edge->getOrig() == node && !visited[edge->getDest()->getId()])
            preorderTraversal(mst, edge->getDest(), visited,preorder);
    }
}

// Function to find the minimum spanning tree and perform preorder traversal
void RealGraph::findMinMSTAndPreorderTraversal(vector<int>& preorder) {
    vector<Edge3*> mst;
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




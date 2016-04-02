#pragma once
#include "Vertex.h"

class Graph
{
private:
    Vertex* graphNodes;
    int numberOfNodes;
    int sourceVertexID;
    bool undirected;

public:
    Graph();

    void inputVertices();
    void inputEdges();
    void BFS();
    void DFS(Vertex*);

    Vertex* getGraphNodes();
    int getNumberOfNodes();
    int getSourceVertexID();

    ~Graph();
};
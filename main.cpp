#include "Graph.h"
#include <conio.h>

int main()
{
    Graph myGraph;

    myGraph.inputVertices();
    myGraph.inputEdges();
    //myGraph.BFS();
    myGraph.DFS(myGraph.getGraphNodes() + myGraph.getSourceVertexID());
    _getch();
    return 0;
}
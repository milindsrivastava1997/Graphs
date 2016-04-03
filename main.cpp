#include "Graph.h"
#include <iostream>
#include <conio.h>

int main()
{
    Graph myGraph;

    myGraph.inputVertices();
    myGraph.inputEdges();
    cout << "BFS" << endl;
    myGraph.BFS();
    cout << endl << "DFS" << endl;
    myGraph.DFS(myGraph.getGraphNodes() + myGraph.getSourceVertexID());
    _getch();
    return 0;
}
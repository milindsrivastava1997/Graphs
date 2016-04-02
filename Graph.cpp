#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph()
{
    graphNodes = nullptr;
    cout << "Enter number of nodes in the graph : ";
    cin >> numberOfNodes;
    graphNodes = new Vertex[numberOfNodes];
    cout << endl << "Is the graph undirected (y for yes, n for no) ? ";
    char c;
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        undirected = true;
    }
    else
    {
        undirected = false;
    }
}

void Graph::inputVertices()
{
    for (int i = 0; i < numberOfNodes; i++)
    {
        int temp;
        cout << "Enter the value of ID = "<<i<<" Node : ";
        cin >> temp;
        cout << endl;
        graphNodes[i].setValue(temp);
        graphNodes[i].setID(i);
    }
    cout << "Enter the ID of the source vertex : ";
    cin >> sourceVertexID;
}

void Graph::inputEdges()
{
    char c = 'n';
    do {
        int sourceID, destinationID;
        cout << endl << "Enter the source vertex ID and destination vertex ID : ";
        cin >> sourceID >> destinationID;
        graphNodes[sourceID].addNeighbour(&graphNodes[destinationID]);
        if (undirected == true)
        {
            graphNodes[destinationID].addNeighbour(&graphNodes[sourceID]);//only if graph is undirected
        }
        cout << endl << "Do you want to enter another edge ? ";
        cin >> c;
    } while (c == 'y' || c == 'Y');
}

void Graph::BFS()
{
    vector<Vertex*> visited;
    vector<Vertex*> frontier;    
    vector<Vertex*> currentVertices;
    Vertex* currentVertex;

    currentVertices.push_back(graphNodes+sourceVertexID);

    while (int(visited.size()) < numberOfNodes)
    {
        cout << "--------------------"<<endl;
        for (int i = 0; i < int(currentVertices.size()); i++)
        {
            visited.push_back(currentVertices[i]);
        }
        for (int i = 0; i < int(currentVertices.size()); i++)
        {
            currentVertex = currentVertices[i];
            cout << currentVertex->getValue();
            if (currentVertex->getParent() != nullptr)
            {
                cout << " Parent ID = " << currentVertex->getParent()->getID();
            }
            cout << endl;
            
            for (int i = 0; i < int(currentVertex->adjList.size()); i++)//for all neighbours of curentVertex
            {
                Vertex* ithNeighbour = currentVertex->adjList[i];
                if (find(visited.begin(), visited.end(), ithNeighbour) == visited.end())//if the ithNeighbour is NOT in visited
                {
                    if (find(frontier.begin(), frontier.end(), ithNeighbour) == frontier.end())//if the ithNeighbour is NOT already in frontier
                    {
                        frontier.push_back(ithNeighbour);//add it to frontier
                        ithNeighbour->setParent(currentVertex);//set parent
                    }
                }
            }
        }
        currentVertices.clear();
        currentVertices.swap(frontier);
    }
}

void Graph::DFS(Vertex* x)
{
    static vector<Vertex*> visited;
    if (find(visited.begin(), visited.end(), x) == visited.end())
    { 
        visited.push_back(x);
    }
    else
    {
        return;
    }
    cout << x->getValue() << endl;
    for (int i = 0; i < int(x->adjList.size()); i++)
    {
        DFS(x->adjList[i]);
    }
}

Vertex* Graph::getGraphNodes()
{
    return graphNodes;
}

int Graph::getNumberOfNodes()
{
    return numberOfNodes;
}

int Graph::getSourceVertexID()
{
    return sourceVertexID;
}

Graph::~Graph()
{
    delete[] graphNodes;
}
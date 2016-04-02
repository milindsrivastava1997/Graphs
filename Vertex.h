#pragma once
#include<vector>
using namespace std;

class Vertex
{
private:
    int ID;
    int value;
    Vertex* parent;

public:
    vector<Vertex*> adjList;
    
    Vertex();
    void setID(int);
    void setValue(int);
    void setParent(Vertex*);

    void addNeighbour(Vertex*);

    int getID();
    int getValue();
    Vertex* getParent();
};
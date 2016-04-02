#include "Vertex.h"

Vertex::Vertex()
{
    ID = -1;
    value = 0;
    parent = nullptr;
}

void Vertex::setID(int x)
{
    ID = x;
}

void Vertex::setValue(int x)
{
    value = x;
}

void Vertex::setParent(Vertex* x)
{
    parent = x;
}

void Vertex::addNeighbour(Vertex* x)
{
    adjList.push_back(x);
}

int Vertex::getID()
{
    return ID;
}

int Vertex::getValue()
{
    return value;
}

Vertex* Vertex::getParent()
{
    return parent;
}
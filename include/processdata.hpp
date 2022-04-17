#pragma once

#include "graph.hpp"

class ProcessData{
    public:

    int depthFirstSearch(Node * start);

    void floydWarshall();

    void shortestDistance(Node * first, Node * target);

    void betweenCenter(int centers);

    private:


};

/* 
 * File:   PQueueNode.h
 * Author: Muhammad Anas
 *
 * Created on May 30, 2012, 2:03 AM
 */

#ifndef PQUEUENODE_H
#define	PQUEUENODE_H

#include <iostream>
using namespace std;

template <class NodeType>
class PQueueNode {
public:
    NodeType info;
    PQueueNode * leftSubTree;
    PQueueNode * rightSubTree;
    PQueueNode * fatherNode;

    PQueueNode(NodeType x, PQueueNode * l = 0, PQueueNode * r = 0, PQueueNode * f = 0) {
        info = x;
        leftSubTree = l;
        rightSubTree = r;
        fatherNode = f;
    }
};

#endif	/* PQUEUENODE_H */


/* 
 * File:   PQueueNode.h
 * Author: Muhammad Anas
 *
 * Created on May 30, 2012, 2:03 AM
 */

#ifndef PQUEUENODE_H
#define	PQUEUENODE_H

class PQueueNode
{
public:
    int info;
    char character;
    PQueueNode * leftSubTree;
    PQueueNode * rightSubTree;
    PQueueNode * fatherNode;

    PQueueNode( int x, PQueueNode * l = 0, PQueueNode * r = 0, PQueueNode * f = 0 )
    {
        info = x;
        leftSubTree = l;
        rightSubTree = r;
        fatherNode = f;
    }
    
    PQueueNode( int x, char c, PQueueNode * l = 0, PQueueNode * r = 0, PQueueNode * f = 0 )
    {
        info = x;
        character = c;
        leftSubTree = l;
        rightSubTree = r;
        fatherNode = f;
    }
};

#endif	/* PQUEUENODE_H */

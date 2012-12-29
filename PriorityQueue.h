/* 
 * File:   PriorityQueue.h
 * Author: Muhammad Anas
 *
 * Created on May 30, 2012, 2:04 AM
 */

#ifndef PRIORITYQUEUE_H
#define	PRIORITYQUEUE_H

#include "PQueueNode.h"
#include "DynamicQueue.h"

#include <iostream>

using namespace std;

class PriorityQueue
{
private:
    PQueueNode * root;
    PQueueNode * lastInserted;
    
    void percolateUp( PQueueNode * );
    void percolateDown();
    void adjustLastInserted();
    void swap( PQueueNode *, PQueueNode * );
    void preOrder( PQueueNode * );
public:
    PriorityQueue();
    
    void enqueue( int );
    int dequeue();
    void preOrder();
};

void PriorityQueue::percolateUp( PQueueNode * ptr )
{
    bool queueValidated = false;
    
    while ( !queueValidated && ptr->fatherNode != 0 )
    {
        if ( ptr->info > ptr->fatherNode->info )
        {
            swap( ptr, ptr->fatherNode );
            ptr = ptr->fatherNode;
        }
        else
            queueValidated = true;
    }
}

void PriorityQueue::percolateDown()
{
    PQueueNode *p = root;
    bool queueValidated = false;
    if (root != 0) {
        while (((p->leftSubTree != 0) || (p->rightSubTree != 0)) && (!queueValidated)) {
            if ((p->rightSubTree != 0) && (p->rightSubTree->info > p->leftSubTree->info)) {
                if (p->rightSubTree->info > p->info) {
                    swap(p, p->rightSubTree);
                    p = p->rightSubTree;
                } else {
                    queueValidated = true;
                }
            } else {
                if (p->leftSubTree->info > p->info) {
                    swap(p, p->leftSubTree);
                    p = p->leftSubTree;
                } else {
                    queueValidated = true;
                }
            }
        }
    }
}

void PriorityQueue::adjustLastInserted()
{
    DynamicQueue<PQueueNode*> queue;
    PQueueNode * temp;
    
    queue.enqueue( root );
    
    while ( !queue.isEmpty() )
    {
        temp = queue.dequeue();
        
        if ( temp->leftSubTree != 0 )
            queue.enqueue( temp->leftSubTree );
        if ( temp->rightSubTree != 0 )
            queue.enqueue( temp->rightSubTree );
    }
    
    lastInserted = temp;
}

void PriorityQueue::swap( PQueueNode * p, PQueueNode * q )
{
    int temp = p->info;
    p->info = q->info;
    q->info = temp;
}

PriorityQueue::PriorityQueue()
{
    root = lastInserted = 0;
}

void PriorityQueue::enqueue( int x )
{
    PQueueNode * ptr = new PQueueNode( x );
    
    if ( root == 0 )
        root = ptr;
    else
    {
        DynamicQueue<PQueueNode*> queue;
        bool nodeInserted = false;
        queue.enqueue( root );
        PQueueNode * temp;
        
        while( !nodeInserted )
        {
            temp = queue.dequeue();
            
            if ( temp->leftSubTree == 0 )
            {
                temp->leftSubTree = ptr;
                ptr->fatherNode = temp;
                nodeInserted = true;
            }
            else if ( temp->rightSubTree == 0 )
            {
                temp->rightSubTree = ptr;
                ptr->fatherNode = temp;
                nodeInserted = true;
            }
            else
            {
                queue.enqueue( temp->leftSubTree );
                queue.enqueue( temp->rightSubTree );
            }
        }
        
        lastInserted = ptr;
        percolateUp( ptr );
    }
}

int PriorityQueue::dequeue()
{
    if ( root != 0 )
    {
        PQueueNode * toDelete;
        
        int value = root->info;
        
        if ( lastInserted != root ) // in that case, lastInserted->fatherNode will be 0 and will cause the program to crash
        {
            root->info = lastInserted->info;
            toDelete = lastInserted;

            if ( lastInserted->fatherNode->rightSubTree == lastInserted )
            {
                lastInserted->fatherNode->rightSubTree = 0;
                lastInserted = lastInserted->fatherNode->leftSubTree;
            }
            else
            {
                lastInserted->fatherNode->leftSubTree = 0;
                adjustLastInserted();
            }
            delete toDelete;
            percolateDown();
        }
        else
        {
            delete root;
            root = 0;
        }
        
        return value;
    }
    else
    {
        cout << "Cannot dequeue because queue is empty." << endl;
        return 0;
    }
}

void PriorityQueue::preOrder()
{
    preOrder( root );
}

void PriorityQueue::preOrder( PQueueNode * ptr )
{
    if ( ptr != 0 )
    {
        cout << ptr->info << endl;
        preOrder( ptr->leftSubTree );
        preOrder( ptr->rightSubTree );
    }
}
#endif	/* PRIORITYQUEUE_H */


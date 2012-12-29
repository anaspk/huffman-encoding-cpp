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

template <class QueueType>
class PriorityQueue
{
private:
    PQueueNode<QueueType> * root;
    PQueueNode<QueueType> * lastInserted;
    
    void percolateUp( PQueueNode<QueueType> * );
    void percolateDown();
    void adjustLastInserted();
    void swap( PQueueNode<QueueType> *, PQueueNode<QueueType> * );
    void preOrder( PQueueNode<QueueType> * );
public:
    PriorityQueue();
    
    void enqueue( QueueType );
    QueueType dequeue();
    void preOrder();
};

template <class QueueType>
void PriorityQueue<QueueType>::percolateUp( PQueueNode<QueueType> * ptr )
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

template <class QueueType>
void PriorityQueue<QueueType>::percolateDown()
{   
    PQueueNode<QueueType> *p = root;
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

template <class QueueType>
void PriorityQueue<QueueType>::adjustLastInserted()
{
    DynamicQueue<PQueueNode<QueueType>*> queue;
    PQueueNode<QueueType> * temp;
    
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

template <class QueueType>
void PriorityQueue<QueueType>::swap( PQueueNode<QueueType> * p, PQueueNode<QueueType> * q )
{
    QueueType temp = p->info;
    p->info = q->info;
    q->info = temp;
}

template <class QueueType>
PriorityQueue<QueueType>::PriorityQueue()
{
    root = lastInserted = 0;
}

template <class QueueType>
void PriorityQueue<QueueType>::enqueue( QueueType x )
{
    PQueueNode<QueueType> * ptr = new PQueueNode<QueueType>( x );
    
    if ( root == 0 )
        root = ptr;
    else
    {
        DynamicQueue<PQueueNode<QueueType>*> queue;
        bool nodeInserted = false;
        queue.enqueue( root );
        PQueueNode<QueueType> * temp;
        
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

template <class QueueType>
QueueType PriorityQueue<QueueType>::dequeue()
{
    if ( root != 0 )
    {
        PQueueNode<QueueType> * toDelete;
        
        QueueType value = root->info;
        
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

template <class QueueType>
void PriorityQueue<QueueType>::preOrder()
{
    preOrder( root );
}

template <class QueueType>
void PriorityQueue<QueueType>::preOrder( PQueueNode<QueueType> * ptr )
{
    if ( ptr != 0 )
    {
        cout << ptr->info << endl;
        preOrder( ptr->leftSubTree );
        preOrder( ptr->rightSubTree );
    }
}
#endif	/* PRIORITYQUEUE_H */


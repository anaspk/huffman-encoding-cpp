/* 
 * File:   DynQueueNode.h
 * Authors: Muhammad Anas and Zafar Iqbal
 *
 * Created on March 13, 2012, 4:28 PM
 */

#ifndef DynQueueNode_H
#define	DynQueueNode_H

template <class queueType>
class DynQueueNode {
public:
    queueType info;
    DynQueueNode<queueType> * next;

    DynQueueNode(queueType temp, DynQueueNode<queueType> * nextAddress = 0) {
        info = temp;
        next = nextAddress;
    }
};

#endif	/* DynQueueNode_H */


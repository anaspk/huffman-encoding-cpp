/* 
 * File:   DynamicQueue.h
 * Authors: Muhammad Anas and Zafar Iqbal
 *
 * Created on March 13, 2012, 4:28 PM
 */

#ifndef DYNAMICQUEUE_H
#define	DYNAMICQUEUE_H

#include <iostream>
#include <fstream>
#include "DynQueueNode.h"
using namespace std;

template <class queueType>
class DynamicQueue {
private:
    DynQueueNode<queueType> * front;
    DynQueueNode<queueType> * rear;
public:
    DynamicQueue();
    DynamicQueue(const DynamicQueue<queueType> &);
    ~DynamicQueue();

    bool isEmpty() const;

    void enqueue(queueType);
    queueType dequeue();
    void display() const;
    void outputToFile(ofstream&) const;
    void clear();
};

template <class queueType>
DynamicQueue<queueType>::DynamicQueue() {
    front = rear = 0;
}

template <class queueType>
DynamicQueue<queueType>::DynamicQueue(const DynamicQueue<queueType> & toCopy) : front(0), rear(0) {
    DynQueueNode<queueType> * temp = toCopy.front;

    while (temp != 0) {
        this->enqueue(temp->info);
        temp = temp->next;
    }
}

template <class queueType>
DynamicQueue<queueType>::~DynamicQueue() {
    clear();
}

template <class queueType>
bool DynamicQueue<queueType>::isEmpty() const {
    return ( front == 0);
}

template <class queueType>
void DynamicQueue<queueType>::enqueue(queueType x) {
    if (isEmpty()) {
        front = rear = new DynQueueNode<queueType > (x);
    } else {
        rear->next = new DynQueueNode<queueType > (x);
        rear = rear->next;
    }
}

template <class queueType>
queueType DynamicQueue<queueType>::dequeue() {
    if (!isEmpty()) {
        queueType temp = front->info;

        if (front == rear) {
            delete front;
            front = rear = 0;
        } else {
            DynQueueNode<queueType> * temp1 = front;
            front = front->next;
            delete temp1;
        }

        return temp;
    }
}

template <class queueType>
void DynamicQueue<queueType>::display() const {
    DynQueueNode<queueType> * temp = front;

    while (temp != 0) {
        cout << temp->info << endl;
        temp = temp->next;
    }
}

template <class queueType>
void DynamicQueue<queueType>::outputToFile(ofstream &outputFile) const {
    DynQueueNode<queueType> * temp = front;

    while (temp != 0) {
        outputFile << temp->info;
        temp = temp->next;
        if (temp != 0)
            outputFile << "; ";
    }
}

template <class queueType>
void DynamicQueue<queueType>::clear() {
    while (!isEmpty())
        dequeue();
}

#endif	/* DYNAMICQUEUE_H */


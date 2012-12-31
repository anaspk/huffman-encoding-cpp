/* 
 * File:   SingleLinkedList.h
 * Author: Muhammad Anas
 *
 * Created on March 7, 2012, 11:12 AM
 */
#ifndef SINGLELINKEDLIST_H
#define	SINGLELINKEDLIST_H

#include <iostream>
using namespace std;
#include "SingleLinkedListNode.h"

template <class listType>
class SingleLinkedList
{
    protected:
        SingleLinkedListNode<listType> * head;
        SingleLinkedListNode<listType> * tail;
        
        SingleLinkedListNode<listType> * find( listType );
    public:
        SingleLinkedList();
        ~SingleLinkedList();

        bool isEmpty();
        
        void addToHead( listType );
        void addToTail( listType );
        listType deleteFromHead();
        listType deleteFromTail();
        void del( listType );
        void print();
        
        bool pubFind( listType );
};

template <class listType>
SingleLinkedList<listType>::SingleLinkedList()
{
    head = tail = 0;
}

template <class listType>
SingleLinkedList<listType>::~SingleLinkedList()
{
    while ( !isEmpty() )
        deleteFromHead();
}

template <class listType>
bool SingleLinkedList<listType>::isEmpty()
{
    return ( head == 0);
}

template <class listType>
void SingleLinkedList<listType>::addToHead( listType x )
{
    SingleLinkedListNode<listType> * temp = new SingleLinkedListNode<listType>( x );
    
    if ( isEmpty() )
        tail = head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }    
}

template <class listType>
void SingleLinkedList<listType>::addToTail( listType x )
{
    SingleLinkedListNode<listType> * temp = new SingleLinkedListNode<listType>( x );
    
    if ( isEmpty() )
        head = tail = temp;
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

template <class listType>
listType SingleLinkedList<listType>::deleteFromHead()
{
    if ( !isEmpty() )
    {
        listType temp1 = head->info;
        
        if ( head == tail )
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            SingleLinkedListNode<listType> * temp2 = head->next;
            delete head;
            head = temp2;
        }
        
        return temp1;
    }
}

template <class listType>
listType SingleLinkedList<listType>::deleteFromTail()
{
    if ( !isEmpty() )
    {
        listType temp1 = tail->info;
        
        if ( head == tail )
        {
            delete tail;
            head = tail = 0;
        }
        else
        {
            SingleLinkedListNode<listType> * temp2 = head;
            
            while ( temp2->next != tail )
                temp2 = temp2->next;
            
            delete tail;            
            tail = temp2;
            tail->next = 0;
        }
        
        return temp1;
    }
}

template <class listType>
void SingleLinkedList<listType>::del( listType x )
{
    if ( !isEmpty() )
    {
        if ( head->info == x )
            deleteFromHead();
        else if ( tail->info == x )
            deleteFromTail();
        else
        {
            SingleLinkedListNode<listType> * temp = head;
            SingleLinkedListNode<listType> * previous = temp;

            while ( temp->info != x && temp->next != 0 )
            {
                previous = temp;
                temp = temp->next;
            }

            if ( temp->info == x )
            {
                previous->next = temp->next;
                delete temp;
            }
        }
    }
}

template <class listType>
void SingleLinkedList<listType>::print()
{
    if ( !isEmpty() )
    {
        SingleLinkedListNode<listType> * temp = head;

        cout << temp->info << endl;

        while ( temp->next != 0 )
        {
            temp = temp->next;
            cout << temp->info << endl;
        }
    }
}

template <class listType>
SingleLinkedListNode<listType> * SingleLinkedList<listType>::find( listType x )
{
    if ( !isEmpty() )
    {
        if ( head == tail )
        {
            if ( head->info == x )
                return head;
            else
                return 0;
        }
        else
        {
            SingleLinkedListNode<listType> * temp = head;

            while ( temp->next != 0 )
            {
                if ( temp->info == x )
                    return temp;

                temp = temp->next;
            }
            
            if ( temp->info == x )
                return temp;
            else
                return 0;
        }
    }
    else
        return 0;
}

template <class listType>
bool SingleLinkedList<listType>::pubFind( listType x )
{
    if ( find( x ) == 0 )
        return false;
    else
        return true;
}

#endif	/* SINGLELINKEDLIST_H */


/* 
 * File:   Node.h
 * Author: Muhammad Anas
 *
 * Created on March 7, 2012, 11:14 AM
 */

#ifndef NODE_H
#define	NODE_H

template <class listType>
class SingleLinkedListNode
{
    public:
        listType info;
        SingleLinkedListNode<listType> * next;
        SingleLinkedListNode( listType x, SingleLinkedListNode<listType> * n = 0)
        {
            info = x;
            next = n;
        }
};

#endif	/* NODE_H */


/* 
 * File:   HuffmanTreeNode.h
 * Author: Anas
 *
 * Created on December 30, 2012, 4:35 AM
 */

#ifndef HUFFMANTREENODE_H
#define	HUFFMANTREENODE_H

#include <iostream>
#include "PQueueNode.h"

using namespace std;

class HuffmanTreeNode
{
public:
    int count;
    char character;
    PQueueNode<HuffmanTreeNode> * leftHuffmanTree;
    PQueueNode<HuffmanTreeNode> * rightHuffmanTree;
    
    HuffmanTreeNode( int x = 0, char c='\0' )
    {
        count = x;
        character = c;
        leftHuffmanTree = 0;
        rightHuffmanTree = 0;
    }
    
    bool operator>( const HuffmanTreeNode& toCompare )
    {
        return (this->count > toCompare.count);
    }
    
    bool operator<( const HuffmanTreeNode& toCompare )
    {
        return (this->count < toCompare.count);
    }
    
    bool operator>=( const HuffmanTreeNode& toCompare )
    {
        return (this->count >= toCompare.count);
    }
    
    bool operator<=( const HuffmanTreeNode& toCompare )
    {
        return (this->count <= toCompare.count);
    }
    
    bool operator!=( const HuffmanTreeNode& toCompare )
    {
        return (this->count != toCompare.count && this->character != toCompare.character );
    }
    
    HuffmanTreeNode operator=( const HuffmanTreeNode& toCompare )
    {
        this->count = toCompare.count;
        this->character = toCompare.character;
        this->leftHuffmanTree = toCompare.leftHuffmanTree;
        this->rightHuffmanTree = toCompare.rightHuffmanTree;
        
        return *this;
    }
    
    friend ostream &operator<<( ostream &out, HuffmanTreeNode node )
    {
        return ( out << "Frequency =  " << node.count << ", character = \'" << node.character << "\'");
    }
};

#endif	/* HUFFMANTREENODE_H */


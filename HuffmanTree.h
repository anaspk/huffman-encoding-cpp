/* 
 * File:   HuffmanTree.h
 * Author: Anas
 *
 * Created on December 26, 2012, 6:12 PM
 */

#ifndef HUFFMANTREE_H
#define	HUFFMANTREE_H

#include <string>
#include <fstream>
#include "PriorityQueue.h"
#include "HuffmanTreeNode.h"

class HuffmanTree : public PriorityQueue<HuffmanTreeNode>
{
private:
    int huffmanCodeBuffer;
    ifstream inputFile;
    ofstream outputFile;
    void huffmanTreePreorder( PQueueNode<HuffmanTreeNode> * p );
public:
//    HuffmanTree( string inputFileName );
    void becomeHuffmanTree();
    void createLookupTabel();
    int lookupHuffmanCode( char character );
    void closeFiles();
    void doCompressedOutput( string outputFileName );
    void decompressFile( string inputFileName, string outputFileName );
    void huffmanTreePreorder();
};

//HuffmanTree::HuffmanTree( string inputFileName )
//{
//    inputFile.open( inputFileName.c_str() );
//}

void HuffmanTree::becomeHuffmanTree()
{
    
}

void HuffmanTree::createLookupTabel()
{
    
}

int HuffmanTree::lookupHuffmanCode( char character )
{
    
}

void HuffmanTree::closeFiles()
{
    
}

void doCompressedOutput( string outputFileName )
{
    
}

void decompressFile( string inputFileName, string outputFileName )
{
    
}

void HuffmanTree::huffmanTreePreorder(){
    huffmanTreePreorder( root );
}

void HuffmanTree::huffmanTreePreorder( PQueueNode<HuffmanTreeNode> * p ) {
    if ( p != 0 ) {
        cout << p->info << endl;
        huffmanTreePreorder( p->info.leftHuffmanTree );
        huffmanTreePreorder( p->info.rightHuffmanTree );
    }
}

#endif	/* HUFFMANTREE_H */


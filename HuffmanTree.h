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
#include "CompressionManager.h"

using namespace std;

class HuffmanTree : public PriorityQueue<HuffmanTreeNode>
{
private:
    int huffmanCodeBuffer;
    ifstream inputFile;
    ofstream outputFile;
    void huffmanTreePreorder( PQueueNode<HuffmanTreeNode> * p );
    void outputCodes( PQueueNode<HuffmanTreeNode> * p, string code );
public:
//    HuffmanTree( string inputFileName );
    void becomeHuffmanTree();
    void createLookupTabel();
    int lookupHuffmanCode( char character );
    void closeFiles();
    void doCompressedOutput( string outputFileName );
    void decompressFile( string inputFileName, string outputFileName );
    void huffmanTreePreorder();
    void outputCodes();
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

void HuffmanTree::outputCodes()
{
    outputCodes( root, "" );
}

void HuffmanTree::outputCodes( PQueueNode<HuffmanTreeNode> * p, string code ) {
    if ( p->info.leftHuffmanTree != 0 ){
        outputCodes( p->info.leftHuffmanTree, code + "0" );
    }
    if ( p->info.rightHuffmanTree != 0  ) {
        outputCodes( p->info.rightHuffmanTree, code + "1" );
    }
    if ( p->info.leftHuffmanTree == 0 && p->info.rightHuffmanTree == 0 ) {
        cout << "Code of " << p->info.character << " is " << code << endl;
    }
}
#endif	/* HUFFMANTREE_H */


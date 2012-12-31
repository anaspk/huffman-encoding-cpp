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
#include "LookupTable.h"

using namespace std;

class HuffmanTree : public PriorityQueue<HuffmanTreeNode>
{
private:
    int huffmanCodeBuffer;
    int hcbUsedBits;
    ifstream inputFile;
    ofstream outputFile;
    LookupTable lookupTable;
    void huffmanTreePreorder( PQueueNode<HuffmanTreeNode> * p );
    void createLookupTable( PQueueNode<HuffmanTreeNode> * p, int code, int usedBits );
    void outputCodes( PQueueNode<HuffmanTreeNode> * p, string code );
protected:
    int insertBit( int number, int bit );
public:
    void becomeHuffmanTree();
    void createLookupTable();
    void closeFiles();
    void doCompressedOutput( string outputFileName );
    void writeCodeToFile( LookupTableRow codeRow );
    void finishOutput();
    void decompressFile( string inputFileName, string outputFileName );
    void huffmanTreePreorder();
    void outputCodes();
};

void HuffmanTree::becomeHuffmanTree()
{
    HuffmanTreeNode node1, node2;
    PQueueNode<HuffmanTreeNode> *pqnode1, *pqnode2;
    HuffmanTreeNode * tempnode3;
    
    while ( !isEmpty() && !isLastElement() ) {
        node1 = dequeue();
        node2 = dequeue();
        pqnode1 = new PQueueNode<HuffmanTreeNode>( node1 );
        pqnode2 = new PQueueNode<HuffmanTreeNode>( node2 );
        tempnode3 = new HuffmanTreeNode( node1.count + node2.count );
        if ( node1 < node2 ) {
            tempnode3->leftHuffmanTree = pqnode1;
            tempnode3->rightHuffmanTree = pqnode2;
        } else {
            tempnode3->rightHuffmanTree = pqnode1;
            tempnode3->leftHuffmanTree = pqnode2;
        }
        
        enqueue( tempnode3 );
    }
}

void HuffmanTree::createLookupTable()
{
    createLookupTable( root, 0, 0 );
//    lookupTable.print();
}

void HuffmanTree::createLookupTable( PQueueNode<HuffmanTreeNode> * p, int code, int usedBits ) {
    if ( p->info.leftHuffmanTree != 0 ){
        createLookupTable( p->info.leftHuffmanTree, insertBit( code, 0 ), usedBits + 1 );
    }
    if ( p->info.rightHuffmanTree != 0  ) {
        createLookupTable( p->info.rightHuffmanTree, insertBit( code, 1 ), usedBits + 1 );
    }
    if ( p->info.leftHuffmanTree == 0 && p->info.rightHuffmanTree == 0 ) {
        lookupTable.addToTail( *(new LookupTableRow( p->info.character, code, usedBits )) );
    }
}

void HuffmanTree::closeFiles()
{
    
}

void HuffmanTree::doCompressedOutput( string inputFileName, string outputFileName )
{
    inputFile.open( inputFileName.c_str() );
    outputFile.open( outputFileName.c_str() );
    char c;
    LookupTableRow codeRow;
    
    huffmanCodeBuffer = 0;
    hcbUsedBits = 0;
    
    c = inputFile.get();
    
    while ( c != EOF ) {
        codeRow = lookupTable.getCodeRow( c );
        writeCodeToFile( codeRow );
    }
    finishOutput();
    
    inputFile.close();
    outputFile.close();
}

void HuffmanTree::writeCodeToFile( LookupTableRow codeRow ) {
    if ( (32 - hcbUsedBits) > codeRow.usedBits ) {
        int code = codeRow.code;
        code = code << (32 - codeRow.usedBits );
        int bit;
        
        for ( int i=0; i<codeRow.usedBits; i++ ) {
            bit = getLeftMostBit( code );
            huffmanCodeBuffer = insertBit( huffmanCodeBuffer, bit );
        }
    }
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

int HuffmanTree::insertBit( int number, int bit ) {
    number = number << 1;
    number = number | bit;
    return number;
}
#endif	/* HUFFMANTREE_H */


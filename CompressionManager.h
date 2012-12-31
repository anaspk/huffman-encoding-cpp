/* 
 * File:   CompressionManager.h
 * Author: Anas
 *
 * Created on December 30, 2012, 2:28 AM
 */

#ifndef COMPRESSIONMANAGER_H
#define	COMPRESSIONMANAGER_H

#include <string>
#include <fstream>
#include "HuffmanTreeNode.h"
#include "HuffmanTree.h"
#include "LookupTable.h"

using namespace std;

class CompressionManager {
private:
    int characterCount[256];
    HuffmanTree huffmanTree;
    LookupTable lookupTable;
    string inputFileName;
    string outputFileName;
    ifstream inputFile;
    ofstream outputFile;
public:
    CompressionManager( string ifile, string ofile );
    void readAndCountCharacters();
    void enqueueCharacters();
    void becomeHuffmanTree();
    
    //void tempUtilFunc();
};

CompressionManager::CompressionManager( string ifile, string ofile ) {
    inputFileName = ifile;
    outputFileName = ofile;
    
    for ( int i=0; i<256; i++ ) {
        characterCount[i] = 0;
    }
    
    readAndCountCharacters();
    enqueueCharacters();
    becomeHuffmanTree();
    huffmanTree.outputCodes();
}

void CompressionManager::readAndCountCharacters() {
    inputFile.open( inputFileName.c_str() );
    char character = inputFile.get();
    while ( character != EOF ) {
        characterCount[character]++;
        character = inputFile.get();
    }
    inputFile.close();
}

void CompressionManager::enqueueCharacters() {
    HuffmanTreeNode * huffmanTreeNode;
    for ( int i=0; i<256; i++ ) {
        if ( characterCount[i] != 0 ) {
            huffmanTreeNode = new HuffmanTreeNode( characterCount[i], static_cast<char>(i) );
            huffmanTree.enqueue( *huffmanTreeNode );
        }
    }
}

void CompressionManager::becomeHuffmanTree() {
    HuffmanTreeNode node1, node2;
    PQueueNode<HuffmanTreeNode> *pqnode1, *pqnode2;
    HuffmanTreeNode * tempnode3;
    
    while ( !huffmanTree.isEmpty() && !huffmanTree.isLastElement() ) {
        //cout << "entered" << endl;
        node1 = huffmanTree.dequeue();
        node2 = huffmanTree.dequeue();
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
        
        huffmanTree.enqueue( tempnode3 );
    }
}
//void CompressionManager::tempUtilFunc() {
////    HuffmanTreeNode emptyNode;
////    HuffmanTreeNode huffmanTreeNode = huffmanTree.dequeue();
////    while ( huffmanTreeNode != emptyNode ) {
////        cout << huffmanTreeNode << endl;
////        huffmanTreeNode = huffmanTree.dequeue();
////    }
//    huffmanTree.huffmanTreePreorder();
//    
//}
#endif	/* COMPRESSIONMANAGER_H */


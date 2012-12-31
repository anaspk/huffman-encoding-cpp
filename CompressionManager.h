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

using namespace std;

class CompressionManager {
private:
    int characterCount[256];
    HuffmanTree huffmanTree;
    string inputFileName;
    string outputFileName;
    ifstream inputFile;
    ofstream outputFile;
public:
    CompressionManager( string ifile, string ofile );
    void readAndCountCharacters();
    void enqueueCharacters();
    
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
    huffmanTree.becomeHuffmanTree();
    huffmanTree.outputCodes();
    huffmanTree.createLookupTable();
    huffmanTree.doCompressedOutput();
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


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
#include "PriorityQueue.h"
#include "HuffmanTree.h"

using namespace std;

class CompressionManager {
private:
    int characterCount[256];
    PriorityQueue characterQueue;
    HuffmanTree huffmanTree;
    string inputFileName;
    string outputFileName;
    ifstream inputFile;
    ofstream outputFile;
public:
    CompressionManager( string ifile, string ofile );
    void readAndCountCharacters();
    void enqueueCharacters();
    void tempUtilFunc();
};

CompressionManager::CompressionManager( string ifile, string ofile ) {
    inputFileName = ifile;
    outputFileName = ofile;
    
    for ( int i=0; i<256; i++ ) {
        characterCount[i] = 0;
    }
    
    readAndCountCharacters();
    enqueueCharacters();
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
    for ( int i=0; i<256; i++ ) {
        if ( characterCount[i] != 0 )
            characterQueue.enqueue( characterCount[i] );
    }
}

void CompressionManager::tempUtilFunc() {
    int charCount = characterQueue.dequeue();
    while ( charCount != 0 ) {
        cout << charCount << endl;
        charCount = characterQueue.dequeue();
    }
}
#endif	/* COMPRESSIONMANAGER_H */


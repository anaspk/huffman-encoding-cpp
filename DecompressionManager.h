/* 
 * File:   DecompressionManager.h
 * Author: Anas
 *
 * Created on December 30, 2012, 2:30 AM
 */

#ifndef DECOMPRESSIONMANAGER_H
#define	DECOMPRESSIONMANAGER_H

#include <string>
#include <iostream>
#include <fstream>

#include "HuffmanTree.h"

using namespace std;

class DecompressionManager {
private:
    int machineBits;
    int biggestInteger;
    ifstream inputFile;
    ofstream outputFile;
protected:
    int getLeftMostBit(int number);
public:
    DecompressionManager(string ifile, string ofile, HuffmanTree * huffmanTree);
    ~DecompressionManager();
};

DecompressionManager::DecompressionManager(string ifile, string ofile, HuffmanTree * huffmanTree) {
    machineBits = sizeof ( int) * 8;
    biggestInteger = 1;
    biggestInteger = biggestInteger << (machineBits - 1);
    inputFile.open( ifile.c_str() );
    outputFile.open( ofile.c_str() );
    
    int number;
    int bit;
    char c;
    
    while ( inputFile >> number ) {
        for ( int i=0; i<machineBits; i++ ) {
            bit = getLeftMostBit( number );
//            cout << "got " << bit << endl;
            c = huffmanTree->moveDecodingPointer( bit );
            if ( c != '\0') {
                outputFile << c;
            }
            number = number << 1;
        }
    }
}

DecompressionManager::~DecompressionManager() {
    inputFile.close();
    outputFile.close();
}

int DecompressionManager::getLeftMostBit(int number) {
    return ( ((number & biggestInteger) == 0) ? 0 : 1);
}
#endif	/* DECOMPRESSIONMANAGER_H */


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
public:
//    HuffmanTree( string inputFileName );
    void becomeHuffmanTree();
    void createLookupTabel();
    int lookupHuffmanCode( char character );
    void closeFiles();
    void doCompressedOutput( string outputFileName );
    void decompressFile( string inputFileName, string outputFileName );
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

#endif	/* HUFFMANTREE_H */


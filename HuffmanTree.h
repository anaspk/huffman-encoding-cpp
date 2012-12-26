/* 
 * File:   HuffmanTree.h
 * Author: Anas
 *
 * Created on December 26, 2012, 6:12 PM
 */

#ifndef HUFFMANTREE_H
#define	HUFFMANTREE_H

#include "PriorityQueue.h"

class HuffmanTree : public PriorityQueue
{
    private:
        int huffmanCodeBuffer;
    public:
        HuffmanTree( string inputFileName );
        void countCharacter( char character );
        void becomeHuffmanTree();
        void createLookupTabel();
        char lookupHuffmanCode( int code, int usedbits );
        void closeFiles();
        void doCompressedOutput( string outputFileName );
        void decompressFile( string inputFileName, string outputFileName );
};

#endif	/* HUFFMANTREE_H */


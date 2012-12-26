/* 
 * File:   Controller.h
 * Author: Anas
 *
 * Created on December 26, 2012, 6:18 PM
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <string>

#include "HuffmanTree.h"
using namespace std;

class Controller
{
private:
    HuffmanTree * huffmanTree;
public:
    void compressFile( string inputFileName, string outputFileName );
    void decompressFile( string inputFileName, string outputFileName );
    ~Controller();
};

Controller::decompressFile( string inputFileName, string outputFileName )
{
    this->huffmanTree->decompressFile( inputFileName, outputFileName );
}

Controller::~Controller()
{
    if ( huffmanTree != 0 )
    {
        delete huffmanTree;
        huffmanTree;
    }
}
#endif	/* CONTROLLER_H */


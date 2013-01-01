/* 
 * File:   main.cpp
 * Author: Anas
 *
 * Created on December 26, 2012, 5:13 PM
 */

#include <iostream>
#include "CompressionManager.h"
#include "HuffmanTree.h"
#include "DecompressionManager.h"

using namespace std;

int main(int argc, char** argv) {
    int choice;
    string inputFileName, outputFileName;
    CompressionManager * compressionManager = 0;
    HuffmanTree * huffmanTree = 0;
    DecompressionManager * decompressionManager = 0;

    do {
        cout << "What do you want to do? Enter:" << endl;
        cout << "1 - to compress a file" << endl;
        cout << "2 - to decompress a file" << endl;
        cout << "Any other number to exit the program" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
            {
                cout << "Please enter name of input file:" << endl;
                cin >> inputFileName;
                cout << "Please enter name of output file:" << endl;
                cin >> outputFileName;
                if ( compressionManager != 0 ) {
                    delete compressionManager;
                    compressionManager = 0;
                }
                compressionManager = new CompressionManager(inputFileName, outputFileName);
                huffmanTree = compressionManager->getHuffmanTree();
                //                compressionManager->tempUtilFunc();
            }
                break;
            case 2:
            {
                cout << "Please enter name of input file:" << endl;
                cin >> inputFileName;
                cout << "Please enter name of output file:" << endl;
                cin >> outputFileName;
                if ( decompressionManager != 0 ) {
                    delete decompressionManager;
                    decompressionManager = 0;
                }
                decompressionManager = new DecompressionManager(inputFileName, outputFileName, huffmanTree);
                delete decompressionManager;
            }
                break;
            default:
                break;
        }

    } while (choice == 1 || choice == 2);

    if ( compressionManager != 0 )
        delete compressionManager;
    
    return 0;
}


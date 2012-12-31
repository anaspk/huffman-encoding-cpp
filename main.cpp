/* 
 * File:   main.cpp
 * Author: Anas
 *
 * Created on December 26, 2012, 5:13 PM
 */

#include <iostream>
#include "CompressionManager.h"
#include "DecompressionManager.h"

using namespace std;

int main(int argc, char** argv) {
    int choice;
    string inputFileName, outputFileName;
    CompressionManager * compressionManager;
    DecompressionManager * decompressionManager;
    
    do {
        cout << "What do you want to do? Enter:" << endl;
        cout << "1 - to compress a file" << endl;
        cout << "2 - to decompress a file" << endl;
        cout << "Any other number to exit the program" << endl;
        cin >> choice;
        
        switch ( choice ) {
            case 1: {
                cout << "Please enter name of input file:" << endl;
                cin >> inputFileName;
                cout << "Please enter name of output file:" << endl;
                cin >> outputFileName;
                compressionManager = new CompressionManager( inputFileName, outputFileName );
//                compressionManager->tempUtilFunc();
                delete compressionManager;
            }
                break;
            case 2: {
                cout << "Please enter name of input file:" << endl;
                cin >> inputFileName;
                cout << "Please enter name of output file:" << endl;
                cin >> outputFileName;
                decompressionManager = new DecompressionManager( inputFileName, outputFileName );
                delete decompressionManager;
            }
                break;
            default:
                break;
        }
        
    } while ( choice == 1 || choice == 2 );
    
    return 0;
}


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
#include <cmath>
#include "PriorityQueue.h"
#include "HuffmanTreeNode.h"
#include "LookupTable.h"

using namespace std;

class HuffmanTree : public PriorityQueue<HuffmanTreeNode> {
private:
    int huffmanCodeBuffer;
    int hcbUsedBits;
    int machineBits;
    int biggestInteger;
    ifstream inputFile;
    ofstream outputFile;
    LookupTable lookupTable;
    void huffmanTreePreorder(PQueueNode<HuffmanTreeNode> * p);
    void createLookupTable(PQueueNode<HuffmanTreeNode> * p, int code, int usedBits);
    void outputCodes(PQueueNode<HuffmanTreeNode> * p, string code);
protected:
    int insertBit(int number, int bit);
    int getLeftMostBit(int number);
public:
    HuffmanTree();
    void becomeHuffmanTree();
    void createLookupTable();
    void doCompressedOutput(string inputFileName, string outputFileName);
    void writeCodeToFile(LookupTableRow codeRow);
    void finishOutput();
    void decompressFile(string inputFileName, string outputFileName);
    void huffmanTreePreorder();
    void outputCodes();
};

HuffmanTree::HuffmanTree() {
    huffmanCodeBuffer = 0;
    hcbUsedBits = 0;
    machineBits = sizeof ( int) * 8;
    biggestInteger = 1;
    biggestInteger = biggestInteger << (machineBits - 1);
}

void HuffmanTree::becomeHuffmanTree() {
    HuffmanTreeNode node1, node2;
    PQueueNode<HuffmanTreeNode> *pqnode1, *pqnode2;
    HuffmanTreeNode * tempnode3;

    while (!isEmpty() && !isLastElement()) {
        node1 = dequeue();
        node2 = dequeue();
        pqnode1 = new PQueueNode<HuffmanTreeNode > (node1);
        pqnode2 = new PQueueNode<HuffmanTreeNode > (node2);
        tempnode3 = new HuffmanTreeNode(node1.count + node2.count);
        if (node1 < node2) {
            tempnode3->leftHuffmanTree = pqnode1;
            tempnode3->rightHuffmanTree = pqnode2;
        } else {
            tempnode3->rightHuffmanTree = pqnode1;
            tempnode3->leftHuffmanTree = pqnode2;
        }

        enqueue(tempnode3);
    }
}

void HuffmanTree::createLookupTable() {
    createLookupTable(root, 0, 0);
    lookupTable.print();
}

void HuffmanTree::createLookupTable(PQueueNode<HuffmanTreeNode> * p, int code, int usedBits) {
    if (p->info.leftHuffmanTree != 0) {
        createLookupTable(p->info.leftHuffmanTree, insertBit(code, 0), usedBits + 1);
    }
    if (p->info.rightHuffmanTree != 0) {
        createLookupTable(p->info.rightHuffmanTree, insertBit(code, 1), usedBits + 1);
    }
    if (p->info.leftHuffmanTree == 0 && p->info.rightHuffmanTree == 0) {
        lookupTable.addToTail(*(new LookupTableRow(p->info.character, code, usedBits)));
    }
}

void HuffmanTree::doCompressedOutput(string inputFileName, string outputFileName) {
    inputFile.open(inputFileName.c_str());
    outputFile.open(outputFileName.c_str());
    char c;
    LookupTableRow codeRow;
    c = inputFile.get();

    while (c != EOF) {
        codeRow = lookupTable.getCodeRow(c);
        writeCodeToFile(codeRow);
        c = inputFile.get();
    }
    finishOutput();

    inputFile.close();
    outputFile.close();
}

void HuffmanTree::writeCodeToFile(LookupTableRow codeRow) {
    int code = codeRow.code;
    code = code << (32 - codeRow.usedBits);
    int bit;

    if ((machineBits - hcbUsedBits) >= codeRow.usedBits) {
        for (int i = 0; i < codeRow.usedBits; i++) {
            bit = getLeftMostBit(code);
            huffmanCodeBuffer = insertBit(huffmanCodeBuffer, bit);
            hcbUsedBits++;
            code = code << 1;
        }
    } else {
        int availableBits = machineBits - hcbUsedBits;
        for (int i = 0; i < availableBits; i++) {
            bit = getLeftMostBit(code);
            huffmanCodeBuffer = insertBit(huffmanCodeBuffer, bit);
            hcbUsedBits++;
            code = code << 1;
        }

        outputFile << huffmanCodeBuffer;

        //        cout << "bits in huffman code buffer from left to right are:" << endl;
        for (int i = 0; i < machineBits; i++) {
            //            cout << getLeftMostBit( huffmanCodeBuffer ) << endl;
            huffmanCodeBuffer = huffmanCodeBuffer << 1;
        }
        hcbUsedBits = 0;

        int remainingBits = codeRow.usedBits - availableBits;

        for (int i = 0; i < remainingBits; i++) {
            bit = getLeftMostBit(code);
            huffmanCodeBuffer = insertBit(huffmanCodeBuffer, bit);
            hcbUsedBits++;
            code = code << 1;
        }
    }
}

void HuffmanTree::finishOutput() {
    //    cout << "Last remaining bits of encoding are:" << endl;
    huffmanCodeBuffer = huffmanCodeBuffer << (machineBits - hcbUsedBits);
    outputFile << huffmanCodeBuffer;
    for (int i = 0; i < hcbUsedBits; i++) {
        //        cout << getLeftMostBit( huffmanCodeBuffer ) << endl;
        huffmanCodeBuffer = huffmanCodeBuffer << 1;
    }
}

void decompressFile(string inputFileName, string outputFileName) {

}

void HuffmanTree::huffmanTreePreorder() {
    huffmanTreePreorder(root);
}

void HuffmanTree::huffmanTreePreorder(PQueueNode<HuffmanTreeNode> * p) {
    if (p != 0) {
        cout << p->info << endl;
        huffmanTreePreorder(p->info.leftHuffmanTree);
        huffmanTreePreorder(p->info.rightHuffmanTree);
    }
}

void HuffmanTree::outputCodes() {
    outputCodes(root, "");
}

void HuffmanTree::outputCodes(PQueueNode<HuffmanTreeNode> * p, string code) {
    if (p->info.leftHuffmanTree != 0) {
        outputCodes(p->info.leftHuffmanTree, code + "0");
    }
    if (p->info.rightHuffmanTree != 0) {
        outputCodes(p->info.rightHuffmanTree, code + "1");
    }
    if (p->info.leftHuffmanTree == 0 && p->info.rightHuffmanTree == 0) {
        cout << "Code of " << p->info.character << " is " << code << endl;
    }
}

int HuffmanTree::insertBit(int number, int bit) {
    number = number << 1;
    number = number | bit;
    return number;
}

int HuffmanTree::getLeftMostBit(int number) {
    return ( ((number & biggestInteger) == 0) ? 0 : 1);
}
#endif	/* HUFFMANTREE_H */


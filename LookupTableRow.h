/* 
 * File:   LookupTableRow.h
 * Author: Anas
 *
 * Created on January 1, 2013, 12:26 AM
 */

#ifndef LOOKUPTABLEROW_H
#define	LOOKUPTABLEROW_H

#include <iostream>
using namespace std;

class LookupTableRow {
public:
    char character;
    int code;
    int usedBits;
    
    LookupTableRow( char ch='\0', int c=0, int b=0 ){
        character = ch;
        code = c;
        usedBits = b;
    }
    
    void insertBit( int bit ) {
        code << 1;
        code = code | bit;
    }
    
    friend ostream &operator<<( ostream &out, LookupTableRow row )
    {
        return ( out << "Code of \'" << row.character << "\' is " << row.code << " with "
                << row.usedBits << " bits used.");
    }
};

#endif	/* LOOKUPTABLEROW_H */


/* 
 * File:   LookupTableRow.h
 * Author: Anas
 *
 * Created on January 1, 2013, 12:26 AM
 */

#ifndef LOOKUPTABLEROW_H
#define	LOOKUPTABLEROW_H

class LookupTableRow {
private:
    char character;
    int code;
    int usedBits;
public:
    LookupTableRow( char ch, int c=0, int b=0 ){
        character = ch;
    }
    
    void insertBit( int bit ) {
        code << 1;
        code = code | bit;
    }
};

#endif	/* LOOKUPTABLEROW_H */


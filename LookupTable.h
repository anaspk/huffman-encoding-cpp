/* 
 * File:   LookupTable.h
 * Author: Anas
 *
 * Created on January 1, 2013, 12:26 AM
 */

#ifndef LOOKUPTABLE_H
#define	LOOKUPTABLE_H

#include "LookupTableRow.h"
#include "SingleLinkedList.h"

class LookupTable : public SingleLinkedList<LookupTableRow> {
    public:
        int getCodeRow( char character );
};

LookupTableRow LookupTable::getCodeRow(char character) {
    if ( !isEmpty() )
    {
        SingleLinkedListNode<LookupTableRow> * temp = head;

        while ( temp->next != 0 )
        {
            if ( temp->info.character == character )
                return temp->info;
        }
    }
}
#endif	/* LOOKUPTABLE_H */


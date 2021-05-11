//
//  LSorter.h
//  LSorter
//
//  Created by Tali Moreshet
//  Copyright © Tali Moreshet. All rights reserved.
//

#ifndef LSorter_h
#define LSorter_h

#include <stdio.h>
#include "LNode.h"

class LSorter {
public:
    LNode* sortList(LNode* head);
    int length(LNode* head);
    void merge(LNode** s1, LNode** e1, LNode** s2, LNode** e2);
    void mergeSort(LNode** head);
};

#endif /* LSorter_h */


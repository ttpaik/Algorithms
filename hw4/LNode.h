//
//  LNode.h
//  LSorter
//
//  Created by Tali Moreshet
//  Copyright ©Tali Moreshet. All rights reserved.
//

#ifndef LNode_h
#define LNode_h

#include <stdio.h>

class LNode {
public:
    int val;
    LNode* next;
    LNode(int x=0);
};

#endif /* LNode_h */

//
//  main.cpp
//  LSorter
//
//  Created by Tali Moreshet
//  Copyright © Tali Moreshet. All rights reserved.
//

#include <iostream>
#include "LNode.h"
#include "LSorter.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LNode LNode1(5);
    LNode LNode2(1);
    LNode LNode3(7);
    LNode LNode4(13);
    LNode LNode5(2);
    LNode LNode6(9);
    LNode LNode7(25);
    LNode LNode8(0);
    LNode LNode9(-70);
    LNode LNode10(0);
    
    LNode1.next = &LNode2;
    LNode2.next = &LNode3;
    LNode3.next = &LNode4;
    LNode4.next = &LNode5;
    LNode5.next = &LNode6;
    LNode6.next = &LNode7;
    LNode7.next = &LNode8;
    LNode8.next = &LNode9;
    LNode9.next = &LNode10;
    
    LSorter solution;
    LNode* head = solution.sortList(&LNode1);
    
    LNode* currnode = head;
    while (currnode != nullptr){
        cout << currnode->val << endl;
        currnode = currnode->next;
    }		

    return 0;
}

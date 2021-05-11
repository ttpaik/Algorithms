//
//  LSorter.cpp
//  LSorter
//
//  Created by Tali Moreshet
//  Copyright ©  Tali Moreshet. All rights reserved.
//

#include <algorithm>
#include <stdio.h>
#include "LSorter.h"
using namespace std;


int LSorter::length(LNode* head) {
    LNode* temp = head;
    int count = 0;
    while (temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return count;
}

void LSorter::merge(LNode** s1, LNode** e1, LNode** s2, LNode** e2) {
    LNode* temp = nullptr;
    if ((*s1)->val > (*s2)->val) {
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        temp = *e1;
        *e1 = *e2;
        *e2 = temp;
        temp = nullptr;
    }
    LNode* astart = *s1;
    LNode* aend = *e1;
    LNode* bstart = *s2;
    LNode* bend = *e2;
    LNode* bnext = (*e2)->next;

    while (astart != aend && bstart != bnext) {
        if (astart->next->val > bstart->val) {
            temp = bstart->next;
            bstart->next = astart->next;
            astart->next = bstart;
            bstart = temp;
        }
        astart = astart->next;
    }
    if (astart == aend)
        astart->next = bstart;
    else
        *e2 = *e1;
}

void LSorter::mergeSort(LNode** head)
{
    if (*head == nullptr)
        return;
    LNode* s1 = nullptr, * e1 = nullptr;
    LNode* s2 = nullptr, * e2 = nullptr;
    LNode* lend = nullptr;
    int len = length(*head);

    for (int g = 1; g < len; g = g * 2) {
        s1 = *head;

        while (s1) {

            bool iter = 0;
            if (s1 == *head) {
                iter = 1;
            }

            int counter = g;
            e1 = s1;
            while (--counter && e1->next) {
                e1 = e1->next;
            }

            s2 = e1->next;
            if (!s2) {
                break;
            }
            counter = g;
            e2 = s2;
            while (--counter && e2->next) {
                e2 = e2->next;
            }

            LNode* temp = e2->next;
            merge(&s1, &e1, &s2, &e2);


            if (iter) {
                *head = s1;
            }

            else {
                lend->next = s1;
            }

            lend = e2;
            s1 = temp;
        }
        lend->next = s1;
    }
}

LNode* LSorter::sortList(LNode* head) {
    if (head != nullptr) {
        mergeSort(&head);
        return head;
    }
}
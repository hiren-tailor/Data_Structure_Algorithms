#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
using namespace std;

class DoubleNode
{
    public:
        int data;
        DoubleNode *dnext;
        DoubleNode *dprev;

        void push_dhead(DoubleNode **head_ref, int new_data);
        void Display(DoubleNode *node);
};

#endif
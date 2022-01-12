#ifndef _STACK_H
#define _STACK_H

#include <iostream>
using namespace std;

class StackNode {
    public:
        int data;
        StackNode *next;
        
        int isEmpty(StackNode *root);
        void push(StackNode **root, int data);
        int pop(StackNode **root);
        int peek(StackNode *root);
};

#endif

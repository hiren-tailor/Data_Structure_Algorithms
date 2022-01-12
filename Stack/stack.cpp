#include "stack.h"

StackNode *newNode(int data)
{
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode; 
}

int StackNode::isEmpty(StackNode *root)
{
    return !root;
}

void StackNode::push(StackNode **root, int data)
{
    StackNode *stackNode = newNode(data);   // |1|->|               |2|->|               
    stackNode->next = *root;                // |1|->|.next <- root  |2|->|.next <- root (1)
    *root = stackNode;                      // |1|->| <- root       |2|->| <- root    
    cout << data << " pushed to stack\n";
}

int StackNode::pop(StackNode **root)
{
    if(isEmpty(*root))
        return INT_MIN;
    StackNode *temp = *root;
    *root =(*root)->next;
    int popped = temp->data;
    delete temp;

    return popped;
}

int StackNode::peek(StackNode *root)
{
    if(isEmpty(root))
        return INT_MIN;
    return root->data;
}
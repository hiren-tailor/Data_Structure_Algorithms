#include "doublelist.h"

void DoubleNode::push_dhead (DoubleNode **head_ref, int new_data)
{
    DoubleNode *new_node = new DoubleNode();
    
    new_node->data = new_data;

    new_node->dnext = (*head_ref);

    new_node->dprev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->dprev = new_node;

    (*head_ref) = new_node;
}

void DoubleNode::Display(DoubleNode *node)
{
    DoubleNode* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->dnext;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";
        last = last->dprev;
    }
}
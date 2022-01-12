#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default Constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//Linked List Class

class LinkedList
{
    Node *head;

public:   
    // Default constructor
    LinkedList() { head = NULL; }

    void display(Node *node);
    void push_head(Node **head_ref, int new_data);
    void append_end(Node **head_ref, int new_data);
    void insertAfter(Node *prev_node, int new_data);
    void insert_pos(Node **head_ref, int new_data, int pos);
    void deleteNode_key(Node **head_ref, int key);
    void deleteNode_pos (Node **head_ref, int pos);
    void delete_full_list (Node **head_ref); 
    void length (Node **head_ref);
    bool search (Node *head, int x); 
    int GetNth(Node *head, int index); 
};

#endif
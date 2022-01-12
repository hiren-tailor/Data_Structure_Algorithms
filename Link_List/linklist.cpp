#include "linklist.h"
#include <assert.h>

void LinkedList::display(Node *head_node)
{
    if (head_node == NULL)
    {
        cout << "List is empty" << endl;
    }

    while (head_node != NULL)
    {
        cout << head_node->data << " ";
        head_node = head_node->next;
    }
    cout << endl;
    // Node *p = head;
    // while (p)
    // {
    //     cout << p->data << " ";
    //     p = p->next;
    // }
    // cout << endl;
}

void LinkedList::push_head(Node **head_ref, int new_data)
{
    Node *new_node = new Node();  //allocate node
    new_node->data = new_data;    //put data into new node
    new_node->next = (*head_ref); //new node pointer to head
    (*head_ref) = new_node;       //move head to the new node
}

void LinkedList::append_end(Node **head_ref, int new_data)
{

    Node *new_node = new Node(); /* 1. allocate node */
    Node *last = *head_ref;      /* used in step 5*/
    new_node->data = new_data;   /* 2. put in the data */
    new_node->next = NULL;       /* 3. This new node is going to be the last node, so make next of it as NULL*/

    if (*head_ref == NULL) /* 4. If the Linked List is empty, then make the new node as head */
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) /* 5. Else traverse till the last node */
    {
        last = last->next;
    }

    last->next = new_node; /* 6. Change the next of last node */
    return;
}

/* Given a node prev_node, insert a new node after the given prev_node */
void LinkedList::insertAfter(Node *prev_node, int new_data)
{
    if (prev_node == NULL) /*1. check if the given prev_node is NULL */
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node();      /* 2. allocate new node */
    new_node->data = new_data;        /* 3. put in the data */
    new_node->next = prev_node->next; /* 4. Make next of new node as next of prev_node */
    prev_node->next = new_node;       /* 5. move the next of prev_node as new_node */
}

//Insert at given position
void LinkedList::insert_pos(Node **head_ref, int new_data, int pos)
{
    Node *new_node = new Node(); //allocate node
    new_node->data = new_data;   //put data into new node

    //store head node
    Node *temp = *head_ref;

    //If need to add at head
    if (pos == 0)
    {
        new_node->next = (*head_ref); //new node pointer to head
        (*head_ref) = new_node;       //move head to the new node
        return;
    }

    //Find the previous node of the node to be added
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        temp->next = new_node;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

//Delete the node with key data
void LinkedList::deleteNode_key(Node **head_ref, int key)
{
    //store head node
    Node *temp = *head_ref;
    Node *prev = NULL;

    //If head node to be delete
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; //change head
        delete temp;
        return;
    }

    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        //If key was not present in the list
        if (temp == NULL)
            return;

        //Unlink the node from linked list
        prev->next = temp->next;

        delete temp;
    }
}

//Delete node with position

void LinkedList::deleteNode_pos(Node **head_ref, int pos)
{
    //If linked list is empty
    if (*head_ref == NULL)
        return;

    //store head node into temp
    Node *temp = *head_ref;

    //If head to be removed
    if (pos == 0)
    {
        //change head
        *head_ref = temp->next;
        delete temp;
        return;
    }

    //find the prev node to be deleted
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    //If not in range
    if (temp == NULL || temp->next == NULL)
        return;

    //store pointer to next node to be deleted
    Node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void LinkedList::delete_full_list(Node **head_ref)
{
    //deref head_ref to get the real head
    Node *current = *head_ref;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}

void LinkedList::length (Node **head_ref)
{
    int count = 0;
    Node *current = *head_ref;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    cout << "Length of Linked List is: " << count << endl;
}

bool LinkedList::search (Node *head, int x)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == x )
            return true;
        current = current->next;
    }
    return false;
}

int LinkedList::GetNth(Node *head, int index)
{
    Node *current = head;
    int count = 0;

    while (current != NULL)
    {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }

    //return 0;
    assert(0);
}
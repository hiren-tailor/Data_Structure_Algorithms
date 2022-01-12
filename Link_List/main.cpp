#include "linklist.h"
#include "linklist.cpp"
#include "doublelist.h"
#include "doublelist.cpp"


int main()
{
    LinkedList list;

    Node *head = NULL;
    DoubleNode *dhead = NULL;
    
    DoubleNode dlist;

    // for (int i=0; i<10; i++)
    // {
    //     list.append_end(&head, i);
    // }

    //list.push_head(&head, 1);

    // list.insertAfter(head->next->next, 33);

    //list.deleteNode_key(&head, 2);

    //list.deleteNode_pos(&head, 5);

    // for (int i=0; i<10; i++)
    // {
    //     list.insert_pos(&head, i, i);
    // }

    // list.display(head);
    
    // //list.delete_full_list(&head);

    // //list.display(head);

    // list.length(&head);

    // list.search(head, 6)? cout << "Yes" : cout << "No" << endl;

    // cout << "Nth data is: " << list.GetNth(head,15) << endl;

    dlist.push_dhead(&dhead,1);
    dlist.push_dhead(&dhead,2);
    dlist.push_dhead(&dhead,3);
    dlist.Display(dhead);

    return 0;
}

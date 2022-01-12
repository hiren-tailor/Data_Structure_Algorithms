#include "stack.h"
#include "stack.cpp"

int main ()
{
    StackNode* root = NULL;

    StackNode stack;

    stack.push(&root, 1);
    stack.push(&root, 2);
    stack.push(&root, 3);
    
    cout << stack.pop(&root) << " popped from stack\n";

    cout << "Top element is " << stack.peek(root) << endl;

    cout<<"Elements present in stack : ";

      //print all elements in stack :
    while(!stack.isEmpty(root))
    {
        // print top element in stack
        cout<<stack.peek(root)<<" ";
        // remove top element in stack
        stack.pop(&root);
    }

    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include "..\Classes\node.cpp"
using namespace std;

node *insert_recursion(node *head, int i, int data)
{

    if (i == 0)
    {
        node *newnode = new node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }
    node *temp = insert_recursion(head->next, i - 1, data);
    head->next = temp;
    return head;
}


int main()
{
    node *head;
    head = takeinput();
    head = insert_recursion(head, 2, 69);
    print(head);
    return 0;
}

#include<iostream>
using namespace std;

// Node Structure

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

// Function to detect loop Method 1

bool isLoop(Node* head){
    Node* curr = head;
    Node* temp = new Node(0);
    while(curr != NULL){

        if(curr -> next == NULL)
            return false;
        
        if(curr -> next == temp)
            return true;

        Node* curr_next = curr -> next;
        curr -> next = temp;
        curr = curr_next;
    }
    return false;
}

// Function to detect loop Method 2

Node* isLoopF(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast)
            break;
    }

    if(slow == fast){
        slow = head;
        while(slow -> next != fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        fast -> next = NULL;
    }
    
    return head;    
}

void printNode(Node *head){
    if(head == NULL)
        return;

    cout<<head -> data<<" ";
    printNode(head->next);
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = second;

//    cout<<isLoop(head)<<endl;
    head = isLoopF(head);
    printNode(head);

    return 0;
}

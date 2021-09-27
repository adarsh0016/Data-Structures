#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

Node* head;

Node* GetNewNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void InsertAtHead(int x){
    Node* newNode = GetNewNode(x);
    if(head == NULL){
        head == newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print(){
    Node* temp = head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reversePrint(){
    Node* temp = head;
    if (temp == NULL) return;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<<temp->data;
        temp = temp->prev;
    }
    cout<<endl;
}

int main(){
    head = NULL;
    InsertAtHead(2); Print(); reversePrint();
    InsertAtHead(3); Print(); reversePrint();
    InsertAtHead(4); Print(); reversePrint();

    return 0;
}
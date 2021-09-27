#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop(){
    Node* temp = top;
    if (top == NULL) return;
    top = temp->next;
    delete temp;
}

int Top(){
    Node* temp = top;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->data;
}

void print(Node* p){
    if (top == NULL) return;
    else if (p == NULL){
        cout<<endl;
        return;
    }
    print(p->next);
    cout<<p->data<<" ";
}


int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    print(top);
    pop();
    print(top);

    return 0;
}
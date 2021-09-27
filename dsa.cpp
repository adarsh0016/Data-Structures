#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;
void Insert(int data, int n){
    Node* temp1 = new Node();
    temp1 -> data = data;
    temp1-> next = NULL;
    if(n == 1){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i =0 ; i<n-2; i++){
        temp2 = temp2-> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void Delete(int n){
    Node* temp = head;
    if(n==1){
        head = temp -> next;
        delete temp;
        return;
    }
    for(int i =0; i<n-2; i++){
        temp = temp -> next;
    }
    Node* temp2 = temp -> next;
    temp -> next = temp2 -> next;
    delete temp2;
}

void Reverse(){
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    while(curr != NULL){
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void Print(){
    Node* temp = head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    head = NULL;
    Insert(2,1);
    Insert(3,2);
    Insert(4,3);
    Insert(5,2);
    Print();
    Reverse();
    Print();

    return 0;
}

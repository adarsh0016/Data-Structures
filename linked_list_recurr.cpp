#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Insert(int data, int n, Node* head){
    Node* temp1 = new Node();
    temp1 -> data = data;
    temp1-> next = NULL;
    if(n == 1){
        temp1 -> next = head;
        head = temp1;
        return head;
    }
    Node* temp2 = head;
    for(int i =0 ; i<n-2; i++){
        temp2 = temp2-> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    return head;
}

Node* Reverse(Node* p,Node* head){
    if(p->next == NULL){
        head = p;
        return head;
    }
    head = Reverse(p->next, head);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
    return head;
}

void Print(Node* p){
    if (p == NULL) 
    {
        cout<<endl;
        return;
    }
    cout<<p->data<<" ";
    Print(p->next);
}

void ReversePrint(Node* p){
    if (p == NULL) return;
    Print(p->next);
    cout<<p->data<<" ";
}


int main(){
    Node* head = NULL;
    head = Insert(2,1,head);
    head = Insert(3,2,head);
    head = Insert(4,3,head);
    head = Insert(5,2,head);
    Print(head);
    head = Reverse(head, head);
    Print(head);

    return 0;
}
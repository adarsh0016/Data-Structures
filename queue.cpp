#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* front = NULL;

Node* rear = NULL;

void Enqueue(int data){
    Node* temp = new Node;
    temp-> data = data;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue(){
    Node* temp = front;
    if (front == NULL) return;
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
        delete temp;
    }
}

int main(){

    return 0;
}
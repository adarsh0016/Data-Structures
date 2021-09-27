#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class st{
    private:
        struct Node{
            int data;
            Node* next;
        };

        Node* getNewNode(int data){
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
        }

    public:

        Node* base = NULL;

        void Insert(int data, int n){
            Node* temp1 = getNewNode(data);
            if(n==1){
                temp1->next = base;
                base = temp1;
            }
            else{
                Node* temp2 = base;
                for(int i = 0; i< n-2; i++){
                    temp2 = temp2->next;
                }
                temp1->next = temp2->next;
                temp2->next = temp1;
            }
        }

        void Push(int data){
            Node* temp = getNewNode(data);
            if(base == NULL){
                base = temp;
            }
            else{
                temp->next = base;
                base = temp;
            }
        }

        void Print(){
            Node* temp = base;
            while (temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void RemoveDuplicate(){
            Node* temp = base;
            Node* next_next;
            if(temp == NULL){
                return;
            }
            while(temp->next != NULL){
                if(temp->data == temp->next->data){
                    next_next = temp->next->next;
                    delete temp->next;
                    temp->next = next_next;
                }
                else{
                    temp = temp->next;
                }
            }
        }

        void MiddleElement(){
            Node* slow = base;
            Node* fast = base;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            cout<<slow->data;
            cout<<endl;
        }

        void nthFromBack(int n){
            Node* current = base;
            int length = 0;
            while(current != NULL){
                length++;
                current = current->next;
            }
            current = base;
            for(int i = 0; i < length - n; i++){
                current = current->next;
            }
            cout<<current->data;
        }

        void InsertAscending(int data){
            Node* current = getNewNode(data);
            Node* temp = base;
            if(base == NULL){
                base = current;
            }
            else{
                while(temp->next && data > temp->next->data){
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }

        void reverse(){
            if(base == NULL){
                return;
            }
            Node* current = base;
            Node* next = NULL, *prev = NULL;
            base = NULL;
            while(current != NULL){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            base = prev;
        }
};

int main(){
    st list;
    list.Push(10);
    list.Push(8);
    list.Push(4);
    list.Push(3);
    list.Push(2);
    list.Push(1);
    list.Print();
    list.reverse();
    list.Print();
}
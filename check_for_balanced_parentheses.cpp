#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class stack1{
    private:
        class Node{
            public:
                string data;
                Node* next;
        };

    public:
        Node* top = NULL;

        void push(char a){
            Node* temp = new Node;
            temp->data = a;
            temp->next = top;
            top = temp;
        }

        void pop(){
            Node* temp = top;
            if (top == NULL){
                return;
            }
            top = temp->next;
            delete temp;
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

        bool empty(){
            if(top == NULL) return true;
            else return false;
        }
};

int main(){
    stack1 s;
    string c;
    cin >> c;
    for(int i = 0; i<c.length(); i++){
        if (c[i] == '('){
            s.push(')');
        }
        else if(c[i] == '['){
            s.push(']');
        }
        else if(c[i] == '{'){
            s.push('}');
        }
        else if (c[i] == ')' || c[i]==']' || c[i]=='}'){
            string a(1,c[i]);
            if(s.top == NULL){
                cout<<"bad"<<endl;
                return 0;
            }
            if((s.top)->data == a){
                s.pop();
            }
            else{
                cout<<"bad"<<endl;
                return 0;
            }
        }
    }
    if (s.empty()){
        cout<<"good"<<endl;
    }
    else{
        cout<<"bad"<<endl;
    }
    return 0;
}
#include <iostream>
#define MAX_SIZE 101

using namespace std;

int A[MAX_SIZE];
int top = -1; 

void Push(int x){
    if(top == MAX_SIZE -1){
        cout<<"error"<<endl;
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        cout<<"error"<<endl;
        return;
    }
    top--;
}
int Top(){
    return A[top];
}

void Print(){
    int i;
    for(i = 0; i<=top; i++){
        cout<<A[i];
    }
    cout<<endl;
}


int main(){
    Push(2); Print();
    Push(5); Print();
    cout<< Top();
    Pop(); Print();

    return 0;
}
#include <iostream>

using namespace std;

struct Node
{
     int data;
     Node* next;
};

void Insert(int x, Node** pointertohead){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = *pointertohead;
    *pointertohead = temp;

}
void Print(Node* head){
    cout<<"List is: ";
    while(head != NULL){
        cout << head->data<<" ";
        head = head ->next;
    }
    cout<<"\n";
}

int main (){
    Node* head;
    head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x, &head);
        Print(head);
    }
return 0;
}

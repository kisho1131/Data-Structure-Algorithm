#include <bits/stdc++.h>
using namespace std;

void insert(int, int);
void print();
struct Node
{
    int data;
    Node*next;
    Node*prev;
};
Node* head;

void insert(int data, int n){
    Node*temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(n==1){
        head = temp;
        return;
    }
    Node*temp1 = head;
    for(int i=0; i<n-1;i++){
        temp1 = temp1->next;
    }
    temp->prev = temp1;
    temp->next = temp1->next;
    temp->next->prev = temp;
    temp1->next = temp;
}
void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(int argc, char const *argv[])
{
    head = NULL;
    insert(24, 1);
    insert(45, 2);
    insert(42, 3);
    print();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head;

void push(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    Node *temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

int countOdd(){
    Node *temp = head;
    int index = 0;
    int sum = 0;
    while(temp!= NULL){
        if(index%2 != 0)
            sum += temp->data;
        index++;
        temp = temp->next;
    }
    return sum;
}

void print(){
    Node *temp =head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    head =  NULL;
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    print();
    cout<<endl;
    int sum = countOdd();
    cout<<sum;
    return 0;
}

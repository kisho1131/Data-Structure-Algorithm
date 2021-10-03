#include <bits/stdc++.h>
using namespace std;

void insert(int, int);
void print();
void delete_element(int);
void print_reverse();
struct Node
{
    int data;
    Node*next;
};

Node* head;

void insert(int data, int n){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(n == 1){
        temp->next = head;
        head = temp;
        return;
    }
    Node* temp1 = head;
    for(int i = 0; i < n-2; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void reverse_list(){
    Node *current, *prev, *last;
    current = head;
    prev  = NULL;
    while(current!= NULL){
        last = current -> next;
        current -> next = prev;
        prev = current;
        current = last;
    }
    head = prev;
}

void delete_element(int n){
    Node* temp = head;
    if (n == 1){
        head = temp->next;
        delete(temp);
    }
    for(int i =0; i<n-2; i++){
        temp = temp->next;
    }
    Node*temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
}

void print_reverse(Node* temp){
    if (temp == NULL)
        return;
    print_reverse(temp->next);
    cout<<temp->data <<" ";
}

int main(int argc, char const *argv[])
{
    head = NULL;
    insert(10, 1);
    insert(20, 2);
    insert(30, 3);
    insert(40, 1);
    print();
    cout<<endl;
    cout<<"Printing the reverse of the linked list: ";
    print_reverse(head);
    cout<<endl;
    delete_element(3);
    cout<<"After deleting the elment:";
    print();
    cout<<endl;
    cout<<"Reversing the link of the linked list:";
    cout<<endl;
    reverse_list();
    print();
    return 0;
}

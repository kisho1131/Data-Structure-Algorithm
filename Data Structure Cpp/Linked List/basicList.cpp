#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};

node *head;

node *createNode(int data){
  node *temp = new node();
  temp->data = data;
  temp->next = NULL;
  return temp;

}

void insert_head(int x){
  if(head ==  NULL)
    head = createNode(x);
  else{
    node *temp = createNode(x);
    temp->next = head;
    head = temp;
  }
}

void insert_tail(int x){
  if(head == NULL)
    head = createNode(x);
  else{
    node *temp = createNode(x);
    node *ptr = head;
    while(ptr->next!=NULL)
      ptr = ptr->next;
    ptr->next = temp;
  }
}

void print_data(){
  if(head == NULL)
    return;
  else{
    node *temp = head;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
  }
}

void insert_pos(int x, int pos){
  if(pos == 0)
   insert_head(x);
  else{
    node *temp = createNode(x);
    node *ptr= head;
    for(int i=0;i<pos-2;i++){
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
  }
}

void delete_ele(int pos){
  if(head == NULL)
    return;
  if(pos == 0){
    node *temp = head;
    head = head->next;
    delete(temp);
  }
  else{
    node *ptr = head;
    for(int i=0;i<pos-2;i++){
      ptr = ptr->next;
    }
    node *temp = ptr->next;
    ptr->next = temp->next;
    delete(temp);
  }
}

int middle_ele(){
  node *ptr = head;
  node *ele = head;
  while(ptr && ptr->next){
    ptr = ptr->next->next;
    ele = ele->next;
  }
  return ele->data;
}

void Reverse(){
  node *current = head;
  node *prev = NULL;
  node *next;
  while(current){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

 void print_revrese(node *head){
  // node *temp = head;
  if(head == NULL)
    return;
  print_revrese(head->next);
  cout<<head->data<<"-->";
}

void reverse_rec(node *ptr){
  if(ptr->next== NULL){
    head = ptr;
    return;
  }
  reverse_rec(ptr->next);
  node *q = ptr->next;
  q->next = ptr;
  ptr->next = NULL;
}

int NthLast(int k){
  node *fast, *slow;
  fast = slow = head;
  for(int i=0;i<k-1;i++){
    fast = fast->next;
  }
  while(fast->next){
    fast = fast->next;
    slow = slow->next;
  }
  return slow->data;
}

void swap_element(int x, int y){
  if(x == y) return;
  node *currX = head;
  node *prevX = NULL;
  while(currX && currX->data !=x){
    prevX = currX;
    currX = currX->next;
  }
  node *currY= head;
  node *prevY = NULL;
  while(currY && currY->data != y){
    prevY = currY;
    currY = currY->next;
  }

  if(currX == NULL || currY==NULL) return;
  if(prevX!=NULL)
    prevX->next = currY;
  else
    head = currY;
  if(prevY!=NULL)
    prevY->next = currX;
  else
    head = currX;
  node *temp = currX->next;
  currX->next = currY->next;
  currY->next = temp;
}

void rotate(){
  node *fast = head;
  node *mid = head;
  node *start = head;
  int n = 0;
  node *temp = head;
  while(temp){
    n++;
    temp = temp->next;
  }
  while(fast && fast->next){
    fast = fast->next->next;
    mid = mid->next;
  }

  node *start2 = mid->next;
  node *curr = mid->next;
  node *prev = NULL;
  mid->next = NULL;
  node *fwd = curr;
  while(curr!=NULL){
    fwd = curr->next;
    curr->next = prev;
    prev = curr;
    curr = fwd;
  }
  node *temp1;
  node *temp2;
  while(n--){
    temp1 = start->next;
    temp2 = start2->next;
    start->next = start2;
    start2->next = temp1;
    start = temp1;
    start2 = temp2;
  }
}

int main(int argc, char const *argv[]) {

  head = NULL;
  // insert_head(20);
  // insert_head(30);
  // insert_head(40);
  // insert_tail(50);
  // insert_tail(60);
  // insert_pos(100, 3);
  // insert_tail()
  // print_data();
  // cout<<endl;
  // delete_ele(3);
  // print_data();
  // cout<<endl;
  // cout<<"Middle Ele: "<<middle_ele();
  // cout<<endl;
  // Reverse();
  // print_data();
  // cout<<endl;
  // print_revrese(head);
  // cout<<endl;
  // cout<<"Reverse Using Recursion: ";
  // reverse_rec(head);
  // print_data();
  // cout<<endl;
  // cout<<"Nth ele from end: ";
  // cout<<NthLast(3);
  // cout<<endl;
  // cout<<"Swapping the Pointer of the List: ";
  // swap_element(40, 60);
  // print_data();
  insert_tail(10);
  insert_tail(20);
  insert_tail(30);
  insert_tail(40);
  insert_tail(50);
  insert_tail(60);
  insert_tail(70);
  print_data();
  rotate();
  cout<<endl;
  print_data();

  return 0;
}

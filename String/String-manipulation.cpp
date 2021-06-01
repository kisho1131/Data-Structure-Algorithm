#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *next;
};

Node *head = NULL;
Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->next = NULL;
  return node;
}
void addLast(int data) {
  if (head == NULL) {
    head = newNode(data);
    return;
  }
  head->next = newNode(data);
}

int PrintList(Node *head) {
  int count = 0;
  if (head == NULL)
    return 0;
  while (head != NULL) {
    count++;
    cout << head->data << endl;
    head = head->next;
  }
  return count;
}
int main() {
  while (1) {
    string str;
    cin >> str;
    if (str == "quit")
      break;
    int pos = str.find(" ");
    cout << pos;
    string num = str.substr(pos + 1);
    cout << num << " ";
    int data = stoi(num);
    addLast(data);
  }
  int count = PrintList(head);
  cout << endl;
  cout << count;
  return 0;
}

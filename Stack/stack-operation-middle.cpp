#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
class DLLNode {
public:
  DLLNode *next;
  int data;
  DLLNode *prev;
};

class myStack {
public:
  DLLNode *head;
  DLLNode *mid;
  int count;
};

myStack *createMyStack() {
  myStack *ms = new myStack();
  ms->count = 0;
  return ms;
}

void push(myStack *ms, int data) {
  DLLNode *newNode = new DLLNode();
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = ms->head;
  ms->count += 1;
  if (ms->count == 1) {
    ms->mid = newNode;
  } else {
    ms->head->prev = newNode;
    if (ms->count % 2 == 0) {
      ms->mid = ms->mid->prev;
    }
  }
  ms->head = newNode;
}

int pop(myStack *ms) {
  if (ms->count == 0) {
    cout << " Stack UnderFlow";
    return -1;
  }
  DLLNode *head = ms->head;
  int item = head->data;
  ms->head = head->next;
  if (ms->head != NULL)
    ms->head->prev = NULL;
  ms->count -= 1;
  if (ms->count % 2 != 0) {
    ms->mid = ms->mid->next;
  }
  free(head);
  return item;
}

int middle(myStack *ms) {
  if (ms->count == 0) {
    cout << "Stack UnderFlow";
    return -1;
  }
  return ms->mid->data;
}

int deleteMid(myStack *ms) {
  int temp = ms->mid->data;
  ms->mid->prev->next = ms->mid->next;
  ms->mid->next->prev = ms->mid->prev->next;

  delete ms->mid;
  return temp;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  myStack *ms = createMyStack();
  push(ms, 11);
  push(ms, 22);
  push(ms, 33);
  push(ms, 44);
  push(ms, 55);
  push(ms, 66);
  push(ms, 77);

  cout << "Item popped is " << pop(ms) << endl;
  cout << "Item popped is " << pop(ms) << endl;
  cout << "Middle Element is " << middle(ms) << endl;
  cout << "deleted mid element " << deleteMid(ms) << endl;

  return 0;
  cout << endl;
  return 0;
}

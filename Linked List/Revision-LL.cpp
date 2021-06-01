#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *next;
};

Node *head = NULL;

// Create a new Node in the Linked List...
Node *CreateNewNode(int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->next = NULL;
  return temp;
}

// Insert the Element in the Head of the Linked List...
void InsertHead(int data) {
  if (head == NULL) {
    head = CreateNewNode(data);
  } else {
    Node *temp = CreateNewNode(data);
    temp->next = head;
    head = temp;
  }
}

// Insert the Element in the Linked List -- Iterative Method...
void InsertElement(int data, int pos) {
  Node *temp = CreateNewNode(data);
  if (pos == 0) {
    InsertHead(data);
  } else {
    Node *ptr = head;
    for (int i = 0; i < pos - 2; i++) {
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
  }
}

// Reverse the Linked List --> Iterative Method...
void ReverseList() {
  Node *fwd = head;
  Node *ptr = head;
  Node *prev = NULL;
  while (ptr) {
    fwd = ptr->next;
    ptr->next = prev;
    prev = ptr;
    ptr = fwd;
  }
  head = prev;
}

// Find the Middle Of the LL -- Two Pointer Approch
int FindMiddleList() {
  Node *fast = head;
  Node *slow = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

void PrintList() {
  Node *ptr = head;
  while (ptr) {
    cout << ptr->data << "-->";
    ptr = ptr->next;
  }
}

// Using Stack --> Space Complexity O(N)
bool PalindromeList() {
  stack<int> st;
  Node *ptr1 = head;
  Node *ptr2 = head;
  while (ptr1) {
    st.push(ptr1->data);
    ptr1 = ptr1->next;
  }
  while (ptr2) {
    int i = st.top();
    st.pop();
    if (i != ptr2->data) {
      return false;
    }
    ptr2 = ptr2->next;
  }
  return true;
}

// Detect the Loop and Count the No of Nodes in the Loop
int CountNodes(Node *head) {
  Node *temp = head;
  int count = 1;
  while (temp != head) {
    count++;
    temp->next;
  }
  return count;
}

int DetectLoop() {
  Node *fast = head;
  Node *slow = head;
  while (slow && fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast)
      return CountNodes(slow);
  }
  return 0;
}

// Merge the Linked List..

Node *MergeList(Node *head1, Node *head2) {
  if (!head1 && !head)
    return nullptr;
  if (!head1)
    return head2;
  if (!head2)
    return head1;
  Node *newHead = nullptr;
  if (head1->data < head2->data) {
    newHead = head1;
    head1 = head1->next;
  } else {
    newHead = head2;
    head2 = head2->next;
  }
  Node *copyHead = newHead;
  while (head1 && head2) {
    if (head1->data < head2->data) {
      newHead->next = head1;
      head1 = head1->next;
      newHead = newHead->next;
    } else {
      newHead->next = head2;
      head2 = head2->next;
      newHead = newHead->next;
    }
    if (head1)
      newHead->next = head1;
    if (head2)
      newHead->next = head2;
  }
  return copyHead;
}

// Remove the nth Node From the End of the Linked list..
void RemoveNthNode(int n) {
  Node *fast = head;
  Node *temp = head;
  for (int i = 0; i < n - 1; i++) {
    fast = fast->next;
  }
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
}

// Intersection of two Linked List...
Node *Intersection(Node *head1, Node *head2) {
  Node *result = nullptr;
  Node **node = &result;
  set<int> s;
  while (head1) {
    s.insert(head1->data);
    head1 = head1->next;
  }
  while (head2) {
    if (s.find(head2->data) != s.end()) {
      *node = new Node(head2->data);
      node = &((*node)->next);
      s.erase(s.find(head2->data)); // Very Important Step to Erase the Element
                                    // from the List
    }
    head2 = head2->next;
  }
  return result;
}

// Pairwise Swaping of the Linked List..
void PairwiseSwapping() {
  Node *temp = head;
  while (temp && temp->next) {
    swap(temp->data, temp->next->data);
    temp = temp->next->next;
  }
}

// Reverse The Linekd List Between M & N...
void ReverseListMN(int m, int n) {
  Node *current = head;
  Node *prev = NULL;
  while (m > 1) {
    prev = current;
    current = current->next;
    m--;
    n--;
  }
  Node *connection = prev;
  Node *tail = current;
  Node *fwd = NULL;
  while (n > 0) {
    fwd = current->next;
    current->next = prev;
    prev = current;
    current = fwd;
    n--;
  }
  if (connection) {
    connection->next = prev;
  } else {
    head = prev;
  }
  tail->next = current;
}

// Reverse the LinkedList in the Group of K...
Node *ReverseInKGroup(Node *head, int k, int n) {
  Node *curr = head;
  Node *prev = NULL;
  Node *fwd = NULL;
  int count = 0;
  if (n >= k) {
    while (curr && count < k) {
      fwd = curr->next;
      curr->next = prev;
      prev = curr;
      curr = fwd;
      count++;
    }
  } else {
    return head;
  }
  if (fwd)
    head->next = ReverseInKGroup(fwd, k, n - k);
  return prev;
}

// Starting of the Main Function...
int main(int argc, char const *argv[]) {
  InsertHead(29);
  InsertHead(60);
  InsertHead(90);
  InsertElement(56, 2);
  PrintList();
  cout << endl;
  cout << "ReverseList: ";
  ReverseList();
  PrintList();
  cout << endl;
  cout << "Middle Element is: " << FindMiddleList();
  cout << endl;
  cout << PalindromeList() << endl;
  if (DetectLoop()) {
    std::cout << "Loop Detected Length = " << DetectLoop() << endl;
  } else {
    cout << "Loop Not Detected Length = " << DetectLoop() << endl;
  }
  return 0;
}

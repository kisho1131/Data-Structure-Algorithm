#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node*next;
};
Node *head;

Node *CreateNode(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void InsertHead(int data) {
    Node *temp = CreateNode(data);
    temp->next = head;
    head = temp;
}
void InsertTail(int data) {
    Node *temp = CreateNode(data);
    Node *tailPtr = head;
    while (tailPtr->next != NULL) {
        tailPtr = tailPtr->next;
    }
    tailPtr->next = temp;
}
void InsertPosition(int data, int pos) {
    if (pos == 1) {
        InsertHead(data);
        return;
    }
    Node *temp = CreateNode(data);
    Node *ptr = head;
    for (int i = 0; i < pos - 2; i++) {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

int returnLen() {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void PrintList() {
    Node *temp = head;
    // int count = 0;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void DeleteNode(int pos) {
    Node *temp = head;
    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
}

void PrintReverse(Node *temp) {
    if (temp == NULL)
        return;
    PrintReverse(temp->next);
    cout << temp->data << " ";
}

void reverseLink() {
    Node *current = head;
    Node *prev = NULL;
    Node *temp;
    while (current != NULL) {
        // save the Next Link
        temp = current->next;
        // Point the Current to the previous
        current->next = prev;
        // Update the Previous and the Current
        prev = current;
        current = temp;
    }
    head = prev;
}
Node *RevRec(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *smallHead = RevRec(head->next);
    Node *current = head;
    current->next->next = current;
    current->next = NULL;
    return smallHead;
}

Node *findMiddle(Node *head) {
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void KthNode(Node *head, int k) {
    Node *fast = head;
    Node *slow = head;
    if (head != NULL) {
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        cout << slow->data;
    }
}

Node *merge(Node *head1, Node *head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *temp;
    if (head1->data < head2->data) {
        temp = head1;
        temp->next = merge(head1->next, head2);
    }
    else {
        temp = head2;
        temp->next = merge(head1, head2->next);
    }
    return temp;
}

Node *mergeSort(Node *head) {
    // Check the base Condition
    if (head == NULL || head->next == NULL)
        return head;
    // Divide the linked list form the Middle Element
    Node *mid = findMiddle(head);
    Node *list1 = head;
    Node *list2 = mid->next;
    mid->next = NULL;
    // Sort both the linked list
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);
    // Merge both the Sorted Linked List:))
    Node *final = merge(list1, list2);
    return final;
}

int length(Node *head) {
    if (head == NULL)
        return 0;
    else
        return (1 + length(head->next));
}

bool Palindrome() {
    Node *slow = head;
    Node *head1 = head;
    stack<int>s;
    while (slow != NULL) {
        s.push(slow->data);
        slow = slow->next;
    }
    while (head1 != NULL) {
        int i = s.top();
        s.pop();
        if (head1->data != i) {
            return false;
        }
        head1 = head1->next;
    }
    return true;
}
void swapElement(Node *head, int x, int y) {
    Node *prevX, *prevY = NULL;
    Node *currX, *currY = head;
    // Check if X and Y are Same
    if (x == y)
        return;
    // Itrate over LinkedList and Move to X
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Iterate over LinkedList and Move to Y
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
    // check if X and Y are present in the List
    if (currX == NULL || currY == NULL)
        return;
// If X is not the head element
    if (prevX != NULL)
        prevX->next = currY;
    else // If X is the head Element
        head = currY;
// If Y is not the head Element
    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;
    // Swap the position of X and Y
    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void rotateKth(int k) {
    Node *temp = head;
    int len = 0;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    len++;
    k = k % len;
    for (int i = 0; i < (len - k); i++) {
        temp->next = head;
        head = head->next;
        temp = temp->next;
        temp->next = NULL;
    }
}
int main(int argc, char const *argv[])
{
    head = NULL;
    InsertHead(20);
    InsertHead(30);
    InsertHead(40);
    InsertHead(50);
    InsertHead(60);
    InsertHead(70);
    InsertTail(90);
    InsertTail(10);
    InsertTail(97);
    InsertTail(98);
    // PrintList();
    // cout<<endl;
    // cout<<"No.of Element in the Linked List: "<<returnLen()<<endl;
    InsertPosition(25, 1);
    InsertPosition(67, 4);
    // cout<<returnLen();
    // cout<<endl;
    InsertPosition(34, 9);
    // PrintList();
    // cout<<endl;
    // cout<<returnLen();
    // cout<<endl;
    cout << "List Before ";
    PrintList();
    cout << endl;
    cout << "Length: " << returnLen() << endl;
    DeleteNode(5);
    cout << "List After ";
    PrintList();
    cout << endl;
    cout << "Length: " << returnLen() << endl;
    cout << "Reverse Print ";
    PrintReverse(head);
    cout << endl;
    reverseLink();
    cout << "After Reversing the Links: ";
    PrintList();
    cout << endl;
    cout << "Recursive: ";
    head = RevRec(head);
    PrintList();
    Node *temp = findMiddle(head);
    cout << endl;
    cout << "Middle Element: " << temp->data;
    cout << endl;
    int k = 6;
    cout << k << " node from the last is -> ";
    KthNode(head, k);
    cout << endl;
    //head = mergeSort(head);
    //cout<<"Sorted List is: ";
    //PrintList();
    cout << endl;
    int l = length(head);
    cout << "Length of the Linked List: " << l;
    cout << endl;
    if (Palindrome()) {
        cout << "True";
    }
    else
        cout << "False";
    //cout<<endl;
    //swapElement(head,40, 10);
    // PrintList();
    cout << endl;
    cout << "List After Rotate ";
    rotateKth(4);
    PrintList();
    cout << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int rear, front;
    int size;
    int *arr;
    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }
    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

void Queue::enQueue(int value){
  if((rear == size-1 && front ==0) || (rear == front-1)){
    cout<<" Queue is full";
    return;
  }

  if(front == -1){
    rear = front = 0;
    arr[front] = value;
  }
  else {
    rear = (rear+1)%size;
    arr[rear] = value;
  }
}

void Queue::displayQueue(){
  if(front == -1){
    cout<<"Queue is Empty: ";
    return;
  }
  if(rear > front){
  for(int i=front;i<=rear;i++){
    cout<<arr[i]<<" ";
  }
}
  else
    {
        for (int i = front; i < size; i++) 
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}

int Queue:: deQueue(){
  if(front ==-1){
    cout<<" Queue is empty: ";
    return -1;
  }
  int data = arr[front];
  front = (front+1)%size;
  return data;
}

int main(int argc, char const *argv[]) {

  Queue q(5);
  q.enQueue(14);
  q.enQueue(22);
  q.enQueue(13);
  q.enQueue(-6);
  q.enQueue(100);
  q.displayQueue();
  cout<<endl;
//   q.enQueue(20);
int data = q.deQueue();
cout<<data;
cout<<endl;
q.enQueue(400);
q.displayQueue();
  return 0;
}

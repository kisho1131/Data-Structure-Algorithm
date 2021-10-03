#include<iostream>
using namespace  std;

class MinHeap{
    int [] arr;
    int size;
    int capacity;

    MinHeap(int c){
        arr = new int [];
        size = 0;
        capacity = c;
    }

    int left(int i){ return 2*i + 1;}
    int right(int i){ return 2*i +2;}
    int parent(int i){ reyurn (i-1)/2;}
}

void MinHeap::Insert(int x){
    if(size == capacity) return;
    size++;
    arr[size-1] = x;
    for(i = size-1; i!=0 && arr[parent(i)] > arr[i]){
        swap(arr[i], arr[parent(i)]);
        i =parent(i);
    }
}

void Minheap::Heapify(int i){
    int lt = left(i);
    int rt = right(i);
    smallest = i;
    if(lt < size && arr[lt] < arr[i])
        smallest = lt;
    if(rt < size && arr[rt] < arr[i])
        smallest = rt;
    if(smallest !=i){
        swap(arr[i], arr[smallest]);
        Heapify(smallest);
    }
}

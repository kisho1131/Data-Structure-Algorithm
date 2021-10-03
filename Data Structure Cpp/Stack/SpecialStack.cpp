#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
    static count int max = 100;
    int arr[max];
    int top;
public:
    Stack{ top = -1;}
    bool isempty();
    bool isfull();
    int pop();
    void push(int x);
    int gettop();
};

bool Stack::isempty(){
    if(top == -1)
        return true;
    return false;
}

bool Stack::isfull(){
    if(top == max-1)
        return true;
    return false;
}

int Stack::pop(){
    if(isempty()){
        cout<<"Under Flow";
        exit(0);
    }
    int x = arr[top];
    top--;
    return x;
}

void Stack::push(int x){
    if(isfull){
        cout<<"Stack Overflow";
        exit(0);
    }
    top++;
    arr[top] = x;
}

int Stack::gettop(){
    if(!isempty)
      return arr[top];
}

class SpecialStack::public Stack{
    Stack min;
public:
    int pop();
    void push(int x);
    int getmin();
};

void SpecialStack::push(int x){
    if(isempty){
        Stack::push(x);
        min.push(x);
    }
    Stack::push(x);
    int y = min.gettop();
    if(x<y)
        min.push(x);
    else
        min.push(y);
}
int SpecialStack::pop(){
    int x = Stack::pop();
    min.pop();
    return x;
}

int SpecialStack::getmin(){
    int x = min.gettop();
    return x;
}

int main(int argc, char const *argv[])
{
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getmin() << endl;
    s.push(5);
    cout << s.getmin();
    return 0;
}


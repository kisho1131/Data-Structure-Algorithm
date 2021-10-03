#include<iostream>
#include<list>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[]) {

  list<int>l1;
  list<string>l2;
  l2.push_back("sumit");
  l2.push_back("hemant");
  l2.push_back("alex");
  l2.push_back("shubham");
  l2.push_back("akku");
  l2.push_back("mamata");
  l2.push_back("mamata");
  l2.push_back("akku");
  cout<<"Initial List: "<<endl;
  for(auto x : l2){
    cout<<x<<"::";
  }
  cout<<endl;
  l2.push_front("webtrills");
  l2.sort();
  l2.reverse();
  cout<<"front ele: "<<l2.front();
  cout<<endl;
  cout<<"Last ele: "<<l2.back()<<endl;

// Remove all the Occurances of the element of the list:)


/*
string f;
cin>>f;
l2.remove(f);
*/


// Erase the particular element form the List
auto itr = l2.begin();
itr++;
itr++;
l2.erase(itr);

// Insert the element in the particular position
auto it = l2.begin();
it++;
l2.insert(it, "Welcome");


  cout<<"Final List: "<<endl;
  for(auto x : l2){
    cout<<x<<"::";
  }
  cout<<endl;
  return 0;
}

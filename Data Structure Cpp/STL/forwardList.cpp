#include<iostream>
#include<forward_list>
using namespace std;

int main(int argc, char const *argv[]) {
  forward_list<int>flist;
  flist.assign({1,2,3,4,5});
  for(auto x : flist)
    cout<<x<<" ";

// insert the element at the first position
flist.push_front(23);
auto ptr = flist.insert_after(flist.begin(), {24,45,67});
cout<<endl;
cout<<"After insert: "<<endl;
for(auto x : flist)
  cout<<x<<" ";

flist.erase_after(ptr); // Delete the element after the given pointer

// Remove the Particular element from the list
flist.remove(45);
cout<<endl;
cout<<"Front Element: "<<flist.front()<<endl;

cout<<endl;
cout<<"After Erase: "<<endl;
for(auto x : flist)
  cout<<x<<" ";

  return 0;
}

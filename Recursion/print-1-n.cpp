#include<iostream>
using namespace std;

void print(int n){
  if(n == 0)
    return;
  cout<<n<<"->";
  print(n-1);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

  int n;
  cin>>n;
  print(n);
  return 0;
}

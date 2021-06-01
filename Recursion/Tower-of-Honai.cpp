#include <iostream>
using namespace std;

void toh_helper(int n, char s, char d, char h) {
  if (n == 1) {
    cout << "Moving Plates: " << n << " from: " << s << " to: " << d << endl;
    return;
  }
  toh_helper(n - 1, s, h, d);
  cout << "Moving Plates: " << n << " from: " << s << " to: " << d << endl;
  toh_helper(n - 1, h, d, s);
}
void toh(int n) { toh_helper(n, 's', 'd', 'h'); }

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  toh(n);
  return 0;
}

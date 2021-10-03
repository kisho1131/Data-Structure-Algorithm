#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
  bool subset[n + 1][sum + 1];
  for (int i = 0; i < n; i++)
    subset[i][0] = true;
  for (int i = 0; i <= sum; i++)
    subset[0][i] = false;
  // fill the entire matrix in the bottom up manner

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (j < arr[i - 1])
        subset[i][j] = subset[i - 1][j];
      if (j > arr[i - 1])
        subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
    }
  }
  return subset[n][sum];
}

int main(int argc, char const *argv[]) {

  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set) / sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
    printf("True");
  else
    printf("False");
  return 0;
}

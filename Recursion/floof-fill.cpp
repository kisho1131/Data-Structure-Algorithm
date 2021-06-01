#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n)                                                          \
  fo(i, n) { cout << a[i] << " "; }
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for (auto it = x.rbegin(); it != x.rend(); it +)
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64
    rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}

const int mod = 1000000007;
const int N = 3e5;
vi v[N];
int a[N];

int totalPath = 0;

/* ========== YOUR CODE HERE ========= */
bool isSafeState(int i, int j, int n, vector<vector<bool>> &visited) {
  return i >= 0 and j >= 0 and i < n and j < n and visited[i][j] == false;
}

void helperFunc(int i, int j, int n, vector<vector<int>> &grid,
                vector<vector<bool>> &visited) {
  if (i == n - 1 and j == n - 1) {
    totalPath++;
    return;
  }
  if (!isSafeState(i, j, n, visited))
    return;
  visited[i][j] = true;
  if (i + 1 < n and grid[i + 1][j] == 0)
    helperFunc(i + 1, j, n, grid, visited);
  if (i - 1 >= 0 and grid[i - 1][j] == 0)
    helperFunc(i - 1, j, n, grid, visited);
  if (j - 1 >= 0 and grid[i][j - 1] == 0)
    helperFunc(i, j - 1, n, grid, visited);
  if (j + 1 < n and grid[i][j + 1] == 0)
    helperFunc(i, j + 1, n, grid, visited);
  visited[i][j] = false;
  return;
}

void solution() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  }
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  helperFunc(0, 0, n, grid, visited);
  cout << totalPath;
}

/* ========== YOUR CODE HERE ========= */

/* ========== Main Function ========= */

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;
  while (t--) {
    solution();
    cout << endl;
  }
  return 0;
}

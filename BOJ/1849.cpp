#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 100001;

int arr[MAX_N];
int tree[MAX_N*4];

int update(int node, int left, int right, int idx, int val)
{
  if (idx < left || right < idx)
    return tree[node];
  if (left == right)
  {
    return tree[node] = val;
  }
  int mid = (left + right) >> 1;
  return tree[node] = update(node * 2, left, mid, idx, val)
    + update(node * 2 + 1, mid + 1, right, idx, val);
}

int query(int node, int left, int right, int serch)
{
  if (left == right)
    return left;
  int mid = (left + right) >> 1;
  if (tree[node * 2] >= serch)
    return query(node * 2, left, mid, serch);
  return query(node * 2 + 1, mid + 1, right, serch - tree[node*2]);
}
int N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    update(1, 1, N, i, 1);
  }
  for (int i = 1; i <= N; ++i)
  {
    int x; cin >> x;
    int idx = query(1, 1, N, x+1);
    arr[idx] = i;
    update(1, 1, N, idx, 0);
  }
  for (int i = 1; i <= N; ++i)
    cout << arr[i] << '\n';
  return 0;
}

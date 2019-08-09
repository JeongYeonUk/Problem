#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 500001;

int arr[MAX_N];
int tree[MAX_N * 4];
int N, M;

int init(int node, int left, int right)
{
  if (left == right)
  {
    return tree[node] = arr[left];
  }
  int mid = (left + right) >> 1;
  return tree[node] = init(node * 2, left, mid)
    + init(node * 2 + 1, mid + 1, right);
}

int update(int node, int left, int right, int idx, int diff)
{
  if (idx < left || right < idx)
    return tree[node];
  if (left == right)
  {
    return tree[node] += diff;
  }
  int mid = (left + right) >> 1;
  return tree[node] = update(node * 2, left, mid, idx, diff)
    + update(node * 2 + 1, mid + 1, right, idx, diff);
}

int query(int node, int left, int right, int serch)
{
  if (left == right)
  {
    return left;
  }
  int mid = (left + right) >> 1;
  if (tree[node * 2] >= serch)
    return query(node * 2, left, mid, serch);
  else
    return query(node * 2 + 1, mid + 1, right, serch - tree[node * 2]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i];
  }
  init(1, 1, N);
  cin >> M;
  for (int i = 1; i <= M; ++i)
  {
    int a; cin >> a;
    if (a == 1)
    {
      int b, c; cin >> b >> c;
      arr[b] = c;
      update(1, 1, N, b, c);
    }
    else if (a == 2)
    {
      int b; cin >> b;
      cout << query(1, 1, N, b) << '\n';
    }
  }

  return 0;
}

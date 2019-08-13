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
int tree[MAX_N * 4];
int post[MAX_N];
int pre[MAX_N];
int N;

int update(int node, int left, int right, int idx, int val)
{
  if (idx < left || right < idx)
    return tree[node];
  if (left == right)
    return tree[node] += val;
  int mid = (left + right) >> 1;
  return tree[node] = update(node * 2, left, mid, idx, val)
    + update(node * 2 + 1, mid + 1, right, idx, val);
}

int query(int node, int left, int right, int qleft, int qright)
{
  if (qright < left || right < qleft)
    return 0;
  if (qleft <= left && right <= qright)
    return tree[node];
  int mid = (left + right) >> 1;
  return query(node * 2, left, mid, qleft, qright)
    + query(node * 2 + 1, mid + 1, right, qleft, qright);
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
  for (int i = 1; i <= N; ++i)
  {
    post[i] = query(1, 1, N, arr[i] + 1, N);
    update(1, 1, N, arr[i], 1);
  }
  memset(tree, 0, sizeof(tree));
  for (int i = N; i > 0; --i)
  {
    pre[i] = query(1, 1, N, 1, arr[i] - 1);
    update(1, 1, N, arr[i], 1);
  }
  ll ret = 0;
  for (int i = 1; i <= N; ++i)
  {
    ret += (ll)pre[i] * (ll)post[i];
  }
  cout << ret << '\n';
  return 0;
}

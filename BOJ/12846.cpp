#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 100001;

int arr[MAX_N];
int tree[MAX_N * 4];
int N;

void init(int node, int left, int right)
{
  if (left == right)
  {
    tree[node] = left;
    return;
  }
  int mid = (left + right) >> 1;
  init(node * 2, left, mid);
  init(node * 2 + 1, mid + 1, right);
  if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]])
    tree[node] = tree[node * 2];
  else
    tree[node] = tree[node * 2 + 1];
}

int query(int node, int left, int right, int qleft, int qright)
{
  if (qright < left || right < qleft)
    return -1;
  if (qleft <= left && right <= qright)
    return tree[node];
  int mid = (left + right) >> 1;
  int m1 = query(node * 2, left, mid, qleft, qright);
  int m2 = query(node * 2 + 1, mid + 1, right, qleft, qright);
  if (m1 == -1)
    return m2;
  else if (m2 == -1)
    return m1;
  else
  {
    if (arr[m1] <= arr[m2])
      return m1;
    else
      return m2;
  }
}

ll solve(int left, int right)
{
  int m = query(1, 1, N, left, right);
  ll ret = (ll)(right - left + 1) * (ll)arr[m];
  if (left <= m - 1)
  {
    ll tmp = solve(left, m-1);
    if (ret < tmp)
      ret = tmp;
  }
  if (m + 1 <= right)
  {
    ll tmp = solve(m + 1, right);
    if (ret < tmp)
      ret = tmp;
  }
  return ret;
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
  cout << solve(1, N) << '\n';

  return 0;
}

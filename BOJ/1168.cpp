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
int N, K;

int update(int node, int left, int right, int idx, int val)
{
  if (idx < left || right < idx)
    return tree[node];
  if (left == right)
    return tree[node] = val;
  int mid = (left + right) >> 1;
  return tree[node] = update(node * 2, left, mid, idx, val)
    + update(node * 2 + 1, mid + 1, right, idx, val);
}

int query(int node, int left, int right, int val)
{
  int mid = (left + right) >> 1;
  if (left == right)
    return left;
  if (tree[node * 2] >= val)
    return query(node * 2, left, mid, val);
  return query(node * 2 + 1, mid + 1, right, val - tree[node * 2]);
}

int squery(int node, int left, int right, int sleft, int sright)
{
  if (sright < left || right < sleft)
    return 0;
  if (sleft <= left && right <= sright)
    return tree[node];
  int mid = (left + right) >> 1;
  return squery(node * 2, left, mid, sleft, sright)
    + squery(node * 2 + 1, mid + 1, right, sleft, sright);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  vector<int> ans;
  for (int i = 1; i <= N; ++i)
  {
    update(1, 1, N, i, 1);
  }
  int mod = N - 1;
  ans.push_back(K);
  update(1, 1, N, K, 0);
  for (int i = 2; i <= N; ++i)
  {
    int ret = (squery(1, 1, N, 1, ans.back()) + K) % mod;
    if (!ret)
      ret = mod;
    ans.push_back(query(1, 1, N, ret));
    update(1, 1, N, ans.back(), 0);
    mod--;
  }
  cout << "<";
  for (int i = 0; i < (int)ans.size(); ++i)
  {
    if (i == ans.size() - 1)
      cout << ans[i] << ">" << '\n';
    else
      cout << ans[i] << ", ";
  }
  return 0;
}

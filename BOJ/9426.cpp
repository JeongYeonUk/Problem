#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 250001;
const int MAX = 65536;

ll arr[MAX_N];
ll tree[MAX_N*4];

ll update(ll node, ll left, ll right, ll idx, ll val)
{
  if (idx < left || right < idx)
    return tree[node];
  if (left == right)
    return tree[node] += val;
  ll mid = (left + right) >> 1;
  return tree[node] = update(node * 2, left, mid, idx, val)
    + update(node * 2 + 1, mid + 1, right, idx, val);
}

ll query(int node, ll left, ll right, ll val)
{
  ll mid = (left + right) >> 1;
  if (left == right)
    return left;
  if (tree[node * 2] >= val)
    return query(node * 2, left, mid, val);
  return query(node * 2 + 1, mid + 1, right, val - tree[node*2]);
}

ll N, K;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  for (int i = 0; i < N; ++i)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < K-1; ++i)
  {
    update(1, 0, MAX-1, arr[i], 1);
  }
  ll ret = 0;
  for (int i = K-1; i < N; ++i)
  {
    update(1, 0, MAX-1, arr[i], 1);
    ret += query(1, 0, MAX-1, (K + 1) / 2);
    update(1, 0, MAX-1, arr[i - K + 1], -1);
  }
  cout << ret << '\n';
  return 0;
}

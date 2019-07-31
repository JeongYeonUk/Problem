#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1000001;

ll arr[MAX_N];
ll tree[MAX_N * 4];
ll lazy[MAX_N * 4];
int N, M, K;

ll init(ll node, ll left, ll right)
{
  if (left == right)
  {
    return tree[node] = arr[left];
  }
  ll mid = (left + right) >> 1;
  return tree[node] = init(node * 2, left, mid)
    + init(node * 2 + 1, mid + 1, right);
}

void update_lazy(ll node, ll left, ll right)
{
  if (lazy[node] != 0)
  {
    tree[node] += (right - left + 1) * lazy[node];
    if (left != right)
    {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_range(ll node, ll left, ll right, ll uleft, ll uright, ll diff)
{
  update_lazy(node, left, right);
  if (uright < left || right < uleft)
    return;
  if (uleft <= left && right <= uright)
  {
    tree[node] += (right - left + 1) * diff;
    if (left != right)
    {
      lazy[node * 2] += diff;
      lazy[node * 2 + 1] += diff;
    }
    return;
  }
  ll mid = (left + right) >> 1;
  update_range(node * 2, left, mid, uleft, uright, diff);
  update_range(node * 2 + 1, mid + 1, right, uleft, uright, diff);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll left, ll right, ll qleft, ll qright)
{
  update_lazy(node, left, right);
  if (qright < left || right < qleft)
    return 0;
  if (qleft <= left && right <= qright)
    return tree[node];

  ll mid = (left + right) >> 1;
  return query(node * 2, left, mid, qleft, qright)
    + query(node * 2 + 1, mid + 1, right, qleft, qright);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i];
  }

  init(1, 1, N);
  for (int i = 1; i <= M + K; ++i)
  {
    int a; cin >> a;
    if (a == 1)
    {
      int b, c, d; cin >> b >> c >> d;
      update_range(1, 1, N, b, c, d);

    }
    else if (a == 2)
    {
      int b, c; cin >> b >> c;
      cout << query(1, 1, N, b, c) << '\n';
    }
  }

  return 0;
}

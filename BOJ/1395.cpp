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

int tree[MAX_N * 4];
int lazy[MAX_N * 4];
int N, M;

void update_lazy(int node, int left, int right)
{
  if (lazy[node] == 0)
    return;
  tree[node] = (right - left+1) - tree[node];
  if (left != right)
  {
    lazy[node * 2] ^= 1;
    lazy[node * 2 + 1] ^= 1;
  }
  lazy[node] = 0;
  return;
}

int update(int node, int left, int right, int uleft, int uright)
{
  update_lazy(node, left, right);
  if (uright < left || right < uleft)
    return tree[node];
  if (uleft <= left && right <= uright)
  {
    lazy[node] ^= 1;
    update_lazy(node, left, right);
    return tree[node];
  }
  int mid = (left + right) >> 1;
  return tree[node] = update(node * 2, left, mid, uleft, uright)
    + update(node * 2 + 1, mid + 1, right, uleft, uright);
}

int query(int node, int left, int right, int qleft, int qright)
{
  update_lazy(node, left, right);
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

  cin >> N >> M;
  for (int i = 1; i <= M; ++i)
  {
    int O; cin >> O;
    if (O)
    {
      int S, T; cin >> S >> T;
      if (S > T)
        swap(S, T);
      cout << query(1, 1, N, S, T) << '\n';
    }
    else if (!O)
    {
      int S, T; cin >> S >> T;
      if (S > T)
        swap(S, T);
      update(1, 1, N, S, T);
    }
  }

  return 0;
}

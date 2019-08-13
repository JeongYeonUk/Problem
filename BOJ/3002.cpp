#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 250001;

int tree[MAX_N * 4][10];
int lazy[MAX_N * 4];
int v[10];
int N, M;

int init(int node, int left, int right, int idx, int val)
{
  if (idx < left || right < idx)
    return tree[node][val];
  if (left == right)
    return tree[node][val] = tree[node][val] + 1;
  int mid = (left + right) >> 1;
  return tree[node][val] = init(node * 2, left, mid, idx, val)
    + init(node * 2 + 1, mid + 1, right, idx, val);
}

void update_lazy(int node, int left, int right)
{
  if (lazy[node] == 0)
    return;
  for (int i = 0; i < 10; ++i)
  {
    v[(i + lazy[node]) % 10] = tree[node][i];
  }
  for (int i = 0; i < 10; ++i)
  {
    tree[node][i] = v[i];
  }
  if (left != right)
  {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
  return;
}

void update_range(int node, int left, int right, int uleft, int uright)
{
  update_lazy(node, left, right);
  if (uright < left || right < uleft)
    return;
  if (uleft <= left && right <= uright)
  {
    lazy[node]++;
    update_lazy(node, left, right);
    return;
  }
  int mid = (left + right) >> 1;
  update_range(node * 2, left, mid, uleft, uright);
  update_range(node * 2 + 1, mid + 1, right, uleft, uright);
  for (int i = 0; i < 10; ++i)
    tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
}

int query(int node, int left, int right, int qleft, int qright)
{
  update_lazy(node, left, right)
;  if (qright < left || right < qleft)
    return 0;
  if (qleft <= left && right <= qright)
  {
    int ret = 0;
    for (int i = 1; i < 10; ++i)
      ret += tree[node][i] * i;
    return ret;
  }
  int mid = (left + right) >> 1;
  return query(node * 2, left, mid, qleft, qright)
    + query(node * 2 + 1, mid + 1, right, qleft, qright);

}

int main()
{
  scanf("%d%d", &N, &M);
  int x;
  for (int i = 1; i <= N; ++i)
  {
    scanf("%1d", &x);
    init(1, 1, N, i, x);
  }
  while (M--)
  {
    int a, b; scanf("%d%d", &a, &b);
    printf("%d\n", query(1, 1, N, a, b));
    update_range(1, 1, N, a, b);
  }

  return 0;
}

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

ll arr[MAX_N];
ll tree[MAX_N * 4];
int N, K;

ll init(int node, int left, int right)
{
  if (left == right)
  {
    return tree[node] = arr[left];
  }
  int mid = (left + right) >> 1;
  return tree[node] = init(node * 2, left, mid)
    * init(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int idx, ll val)
{
  if (idx < left || right < idx)
    return;
  if (left == right)
  {
    tree[node] = val;
    return;
  }
  int mid = (left + right) >> 1;
  update(node * 2, left, mid, idx, val);
  update(node * 2 + 1, mid + 1, right, idx, val);
  tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

ll query(int node, int left, int right, int qleft, int qright)
{
  if (qright < left || right < qleft)
    return 1;
  if (qleft <= left && right <= qright)
    return tree[node];
  int mid = (left + right) >> 1;
  return query(node * 2, left, mid, qleft, qright)
    * query(node * 2 + 1, mid + 1, right, qleft, qright);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  while (cin >> N >> K)
  {
    for (int i = 1; i <= N; ++i)
    {
      int node; cin >> node;
      if (node > 0)
        update(1, 1, N, i, 1);
      else if (node < 0)
        update(1, 1, N, i, -1);
      else
        update(1, 1, N, i, 0);
    }
    for (int i = 1; i <= K; ++i)
    {
      char cmd; cin >> cmd;
      if (cmd == 'C')
      {
        int idx; ll val; cin >> idx >> val;
        if (val > 0)
          update(1, 1, N, idx, 1);
        else if (val < 0)
          update(1, 1, N, idx, -1);
        else
          update(1, 1, N, idx, 0);
      }
      else if (cmd == 'P')
      {
        int start, end; cin >> start >> end;
        ll ret = query(1, 1, N, start, end);
        if (!ret)
          cout << "0";
        else
          cout << (ret > 0 ? '+' : '-');
      }
    }
    cout << "";
  }

  return 0;
}


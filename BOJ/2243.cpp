#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 1000001;
int N;

ll seg[MAX_N * 4];

ll update(int node, int left, int right, ll idx, ll val)
{
  if (idx < left || right < idx)
    return seg[node];
  if (left == right)
    return seg[node] += val;
  int mid = (left + right) >> 1;
  return seg[node] = update(node * 2, left, mid, idx, val)
    + update(node * 2 + 1, mid + 1, right, idx, val);
}

ll query(int node, int left, int right, ll serch)
{
  int mid = (left + right) >> 1;
  if (left == right)
  {
    cout << left << '\n';
    return left;
  }
  if (seg[node * 2] >= serch)
    return query(node * 2, left, mid, serch);
   return query(node * 2 + 1, mid + 1, right, serch - seg[node*2]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    int A; cin >> A;
    if (A == 1)
    {
      ll B; cin >> B;
      ll ret = query(1, 0, MAX_N-1, B);
      update(1, 0, MAX_N-1, ret, (ll)-1);
    }
    else if (A == 2)
    {
      ll B, C; cin >> B >> C;
      update(1, 0, MAX_N-1, B, C);
    }
  }

  return 0;
}

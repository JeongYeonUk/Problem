#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 100001;

ll tree[MAX_N * 8];
vector<ll> ypos;

struct node
{
  ll x1, y1, x2, y2;
};
struct element
{
  ll x, y, z;
  bool operator < (const element& A) const
  {
    return x > A.x;
  }
};

node arr[MAX_N];
bool cmp(node& a, node& y)
{
  return a.x1 < y.x1;
}

int N;
ll update(ll node, ll left, ll right, ll idx, ll val)
{
  if (idx < left || right < idx)
    return tree[node];
  if (left == right)
    return tree[node] = max(val, tree[node]);
  ll mid = (left + right) >> 1;
  return tree[node] = max(update(node * 2, left, mid, idx, val)
    , update(node * 2 + 1, mid + 1, right, idx, val));
}

ll query(ll node, ll left, ll right, ll qleft, ll qright)
{
  if (qright < left || right < qleft)
    return 0;
  if (qleft <= left && right <= qright)
    return tree[node];
  ll mid = (left + right) >> 1;
  return max(query(node * 2, left, mid, qleft, qright)
    , query(node * 2 + 1, mid + 1, right, qleft, qright));
}

ll get_ypos(ll pos)
{
  return lower_bound(ypos.begin(), ypos.end(), pos) - ypos.begin();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    arr[i] = { x1,y1,x2,y2 };
    ypos.push_back(y1);
    ypos.push_back(y2);
  }
  sort(arr, arr + N, cmp);
  sort(ypos.begin(), ypos.end());
  ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
  const ll MAXY = ypos.size();
  priority_queue<element> pq;

  for (int i = 0; i < N; ++i)
  {
    while (!pq.empty() && pq.top().x < arr[i].x1)
    {
      ll p = get_ypos(pq.top().y);
      update(1, 0, MAXY - 1, p, pq.top().z);
      pq.pop();
    }
    ll p = get_ypos(arr[i].y1);
    ll q = query(1, 0, MAXY - 1, 0, p - 1);
    pq.push({ arr[i].x2, arr[i].y2, q + 1 });
  }
  while (!pq.empty())
  {
    ll p = get_ypos(pq.top().y);
    update(1, 0, MAXY - 1, p, pq.top().z);
    pq.pop();
  }
  cout << tree[1] << '\n';
  return 0;
}

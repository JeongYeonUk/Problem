#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 3000;

ll N, x, y, z, res;
vector<ll> ypos;
ll Max(ll a, ll b, ll c, ll d, ll e)
{
  return max(max(a, b), max(c, max(d, e)));
}

struct element
{
  ll x, y, z;
  bool operator<(const element& A)const
  {
    return x < A.x;
  }
};
struct mseg
{
  ll lsum, rsum, tsum, msum;
};
mseg seg[MAX_N * 4];
element ele[MAX_N];
ll get_ypos(ll pos)
{
  return lower_bound(ypos.begin(), ypos.end(), pos) - ypos.begin();
}

void update(ll pos, ll val, ll node, ll x, ll y)
{
  if (y < pos || pos < x)
    return;
  if (x == y)
  {
    seg[node].tsum += val;
    seg[node].lsum += val;
    seg[node].rsum += val;
    seg[node].msum += val;
    return;
  }
  ll mid = (x + y) >> 1;
  update(pos, val, node * 2, x, mid);
  update(pos, val, node * 2 + 1, mid + 1, y);
  seg[node].lsum = max(seg[node * 2].lsum, seg[node * 2].tsum + seg[node * 2 + 1].lsum);
  seg[node].rsum = max(seg[node * 2 + 1].rsum, seg[node * 2 + 1].tsum + seg[node * 2].rsum);
  seg[node].tsum = seg[node * 2].tsum + seg[node * 2 + 1].tsum;
  seg[node].msum = Max(seg[node * 2].rsum + seg[node * 2 + 1].lsum, seg[node * 2].msum, seg[node * 2 + 1].msum, seg[node].lsum, seg[node].rsum);
}

ll query(ll lo, ll hi, ll node, ll x, ll y)
{
  if (y < lo || hi < x)
    return 0;
  if (lo <= x && y <= hi)
    return seg[node].msum;
  ll mid = (x + y) >> 1;
  return max(query(lo, hi, node * 2, x, mid), query(lo, hi, node * 2 + 1, mid + 1, y));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    cin >> x >> y >> z;
    ele[i] = { x,y,z };
    ypos.push_back(y);
  }
  sort(ele, ele + N);
  sort(ypos.begin(), ypos.end());
  ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
  const ll MAX_Y = ypos.size();
  for (int i = 0; i < N; ++i)
  {
    memset(seg, 0, sizeof(seg));
    if (i && ele[i].x == ele[i - 1].x)
      continue;
    for (int j = i; j < N; ++j)
    {
      ll pos = get_ypos(ele[j].y);
      update(pos, ele[j].z, 1, 0, MAX_Y - 1);
      if (j != N - 1 && ele[j].x == ele[j + 1].x)
        continue;
      ll q = query(0, MAX_Y - 1, 1, 0, MAX_Y - 1);
      res = max(q, res);
    }
  }
  cout << res << '\n';
  return 0;
}

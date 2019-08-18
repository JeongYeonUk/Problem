#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 3001;

ll max(ll a, ll b, ll c, ll d, ll e)
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
vector<ll> ypos;
int N;
ll gety(ll pos)
{
  return lower_bound(ypos.begin(), ypos.end(), pos) - ypos.begin();
}

void update(ll node, ll left, ll right, ll idx, ll val)
{
  if (idx < left || right < idx)
    return;
  if (left == right)
  {
    seg[node].tsum += val;
    seg[node].lsum += val;
    seg[node].rsum += val;
    seg[node].msum += val;
    return;
  }
  ll mid = (left + right) >> 1;
  update(node * 2, left, mid, idx, val);
  update(node * 2 + 1, mid + 1, right, idx, val);
  seg[node].lsum = max(seg[node * 2].lsum, seg[node * 2].tsum + seg[node * 2 + 1].lsum);
  seg[node].rsum = max(seg[node * 2 + 1].rsum, seg[node * 2].rsum + seg[node * 2 + 1].tsum);
  seg[node].tsum = seg[node * 2].tsum + seg[node * 2 + 1].tsum;
  seg[node].msum = max(seg[node * 2].rsum + seg[node * 2 + 1].lsum, seg[node * 2].msum, seg[node * 2 + 1].msum, seg[node].lsum, seg[node].rsum);
}

ll query(ll node, ll left, ll right, ll qleft, ll qright)
{
  if (qright < left || right < qleft)
    return 0;
  if (qleft <= left && right <= qright)
    return seg[node].msum;
  ll mid = (left + right) >> 1;
  return max(query(node * 2, left, mid, qleft, qright)
    , query(node * 2 + 1, mid + 1, right, qleft, qright));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    ll x, y, z; cin >> x >> y >> z;
    ele[i] = { x,y,z };
    ypos.push_back(y);
  }
  sort(ele, ele + N);
  sort(ypos.begin(), ypos.end());
  ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
  const ll MAXY = ypos.size();
  ll ret = 0;
  for (int i = 0; i < N; ++i)
  {
    memset(seg, 0, sizeof(seg));
    if (i && ele[i].x == ele[i - 1].x)
      continue;
    for (int j = i; j < N; ++j)
    {
      ll pos = gety(ele[j].y);
      update(1, 0, MAXY - 1, pos, ele[j].z);
      if (j != N - 1 && ele[j].x == ele[j + 1].x)
        continue;
      ll q = query(1, 0, MAXY - 1, 0, MAXY - 1);
      ret = max(q, ret);
    }
  }
  cout << ret << '\n';
  return 0;
}

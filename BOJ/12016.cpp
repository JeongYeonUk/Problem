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

int N;
ll v;
pll arr[MAX_N];
ll tree[MAX_N];
ll res[MAX_N];

void update(ll idx, ll val)
{
  while (idx <= N)
  {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

ll sum(ll idx)
{
  ll ret = 0;
  while (idx > 0)
  {
    ret += tree[idx];
    idx -= (idx & -idx);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    update(i, 1);
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr+1, arr + N+1);

  for (int i = 1; i <= N; ++i)
  {
    pll y = arr[i];
    ll idx = y.second;
    ll ret = sum(idx) * y.first
      + ((sum(N) - sum(idx)) * (y.first - 1)) + v;
    v += y.first;
    res[idx] = ret;
    update(idx, -1);
  }

  for (int i = 1; i <= N; ++i)
  {
    cout << res[i] << '\n';
  }
  return 0;
}

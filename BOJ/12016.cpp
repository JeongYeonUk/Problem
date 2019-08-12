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

pll arr[MAX_N];
ll tree[MAX_N];
ll res[MAX_N];
int N;
ll t;
void update(int i, ll val)
{
  while (i <= N)
  {
    tree[i] += val;
    i += (i & -i);
  }
}

ll sum(ll i)
{
  ll ret = 0;
  while (i > 0)
  {
    ret += tree[i];
    i -= (i & -i);
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
    arr[i].second = (ll)i;
  }
  sort(arr + 1, arr + N + 1);

  for (int i = 1; i <= N; ++i)
  {
    pll y = arr[i];
    ll ret = (sum(y.second) * y.first)
      + ((sum(N) - sum(y.second)) * (y.first - 1)) + t;
    t += y.first;
    res[y.second] = ret;
    update(y.second, -1);
  }

  for (int i = 1; i <= N; ++i)
  {
    cout << res[i] << '\n';
  }

  return 0;
}

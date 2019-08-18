#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 200001;
const int MOD = 1000000007;

ll cnt[MAX_N];
ll seg[MAX_N];
int N;

void update(ll* arr, int idx, ll val)
{
  for (int i = idx; i <= MAX_N; i += (i & -i))
    arr[i] += val;
}

ll _sum(ll* arr, int idx)
{
  ll ret = 0;
  for (int i = idx; i > 0; i -= (i & -i))
    ret += arr[i];
  return ret;
}

ll sum(ll* arr, int s, int e)
{
  if (s > e) return 0;
  return (_sum(arr, e) - _sum(arr, s - 1));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  ll ret = 1;
  for (int i = 0; i < N; ++i)
  {
    int x; cin >> x;
    x += 1;
    if (i)
    {
      ll front = (sum(cnt, 1, x - 1) * x) - sum(seg, 1, x - 1);
      ll back = (sum(seg, x + 1, MAX_N-1)) - (sum(cnt, x + 1, MAX_N-1) * x);
      ret *= (front + back) % MOD;
      ret %= MOD;
    }
    update(cnt, x, 1LL);
    update(seg, x, x);
  }

  cout << ret << '\n';

  return 0;
}

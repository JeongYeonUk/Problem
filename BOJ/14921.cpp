#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100001;

ll arr[MAX];
int n;
ll mini;
ll abs(ll a)
{
  return a > 0 ? a : -a;
}

ll solve()
{
  int lp = 0, rp = n - 1;
  while (lp < rp)
  {
    ll sum = arr[lp] + arr[rp];
    if (abs(sum) < abs(mini))
      mini = sum;
    if (sum < 0)
      ++lp;
    else
      --rp;
  }
  return mini;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &arr[i]);

  mini = LLONG_MAX;
  printf("%lld\n", solve());
  return 0;
}

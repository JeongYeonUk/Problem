#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

bool visit[110];
int dp[110][110];
int n, m;

int solve(int day, int coupon)
{
  if (n < day)
    return 0;
  int& ret = dp[day][coupon];
  if (ret != -1)
    return ret;
  return ret = visit[day]
    ? solve(day + 1, coupon)
    : min({ coupon >= 3
      ? solve(day + 1, coupon - 3)
      : solve(day + 1,coupon) + 10000
      , solve(day + 3, coupon + 1) + 25000
      , solve(day + 5, coupon + 2) + 37000 });
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
  {
    int x; cin >> x; visit[x] = 1;
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(1, 0);

  return 0;
}

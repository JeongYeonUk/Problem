#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int dp[2010][2010];
int l[2010];
int r[2010];
int N;

int solve(int ldx, int rdx)
{
  if (ldx >= N || rdx >= N)
  {
    return 0;
  }
  int& ret = dp[ldx][rdx];
  if (ret != -1) return ret;
  ret = 0;
  ret = max(solve(ldx + 1, rdx), solve(ldx + 1, rdx + 1));
  if (l[ldx] > r[rdx])
    ret = max(ret, solve(ldx, rdx + 1) + r[rdx]);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> l[i];
  for (int i = 0; i < N; ++i) cin >> r[i];
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0) << '\n';
  return 0;
}

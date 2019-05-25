#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int money[4];
int month[13];
int dMonth[13];
int dp[13];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 4; ++i)
    {
      cin >> money[i];
    }
    for (int i = 1; i <= 12; ++i)
    {
      cin >> month[i];
    }
    for (int i = 1; i <= 12; ++i)
    {
      dMonth[i] = min(month[i] * money[0], money[1]);
    }
    for (int i = 1; i <= 12; ++i)
    {
      dp[i] = dp[i - 1] + dMonth[i];
      if (i - 3 >= 0)
      {
        if (dp[i] > dp[i - 3] + money[2])
          dp[i] = dp[i - 3] + money[2];
      }
    }

    if (dp[12] > money[3])
      dp[12] = money[3];

    cout << '#' << cases << ' ' << dp[12] << '\n';
  }

  return 0;
}

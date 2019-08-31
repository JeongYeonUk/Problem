#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

long long dp[81];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i <= N; ++i)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << (((dp[N] << 1) + dp[N - 1]) << 1) << '\n';

  return 0;
}

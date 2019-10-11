#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int n;
int T[15], P[15];
int cache[15];

int solve(int day)
{
  if (day > n)
    return -INF;
  if (day == n)
    return 0;
  int& ret = cache[day];
  if (ret != -1)
    return ret;

  return ret = max(solve(day + 1), solve(day + T[day]) + P[day]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> T[i] >> P[i];
    cache[i] = -1;
  }

  int ret = solve(0);
  cout << ret << endl;

  return 0;
}

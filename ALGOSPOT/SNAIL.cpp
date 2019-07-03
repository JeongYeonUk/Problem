#include <iostream>
#include <cstring>
using namespace std;

inline int MAX(int a, int b)
{
  return a > b ? a : b;
}

inline int MIN(int a, int b)
{
  return a > b ? b : a;
}

int n, m;
double cache[1001][2*1001];

double climb(int days, int climbed)
{
  if (days == m)
    return climbed >= n ? 1 : 0;
  double& ret = cache[days][climbed];
  if (ret != -1.0)
    return ret;
  return ret = 0.25 * climb(days + 1, climbed + 1)
    + 0.75 * climb(days + 1, climbed + 2);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {
    cin >> n >> m;
    for (int i = 0; i < 1001; ++i)
    {
      for (int j = 0; j < 2002; ++j)
      {
        cache[i][j] = -1.0;
      }
    }
    cout.precision(11);
    cout << climb(0, 0) << '\n';
  }

  return 0;
}

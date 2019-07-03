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

int arr[100];
int cache[101];

int solve(int width)
{
  if (width <= 1) return 1;
  int& ret = cache[width];
  if (ret != -1) return ret;
  return ret = (solve(width - 1) + solve(width - 2)) % 1000000007;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
      arr[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(n) << '\n';
  }

  return 0;
}

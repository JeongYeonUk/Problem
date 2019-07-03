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

int tri[101][101];
int cache[101][101];
int cntCache[101][101];
int N;

int path(int y, int x)
{
  if (y == N - 1) return tri[y][x];
  int& ret = cache[y][x];
  if (ret != -1) return ret;
  return ret = MAX(path(y + 1, x), path(y + 1, x + 1)) + tri[y][x];
}

int solve(int y, int x)
{
  if (y == N - 1) return 1;
  int& ret = cntCache[y][x];
  if (ret != -1) return ret;
  ret = 0;
  if (path(y + 1, x + 1) >= path(y + 1, x))
    ret += solve(y + 1, x + 1);
  if (path(y + 1, x + 1) <= path(y + 1, x))
    ret += solve(y + 1, x);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j <= i; ++j)
      {
        cin >> tri[i][j];
      }
    }
    memset(cache, -1, sizeof(cache));
    memset(cntCache, -1, sizeof(cntCache));

    cout << solve(0,0) << '\n';
  }

  return 0;
}

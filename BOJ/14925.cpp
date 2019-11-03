#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int map[1001][1001];

int min(int a, int b, int c)
{
  int ret = a > b ? b : a;
  ret = ret > c ? c : ret;
  return ret;
}

int main()
{
  int m, n; scanf("%d %d", &m, &n);
  int ret = 0;
  for (int y = 1; y <= m; ++y)
  {
    for (int x = 1; x <= n; ++x)
    {
      int num; scanf("%d", &num);
      if (num == 0)
      {
        map[y][x] = 1;
        map[y][x] = min(map[y - 1][x - 1], map[y - 1][x], map[y][x - 1]) + 1;
        ret = ret > map[y][x] ? ret : map[y][x];
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}

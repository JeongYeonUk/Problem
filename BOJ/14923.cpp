#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

bool map[1002][1002];
int check[1002][1002][2];
int q[3000000][4], n, m;

enum TYPE
{
  X = 0, Y = 1, T = 2, M = 3
};

int main()
{
  scanf("%d %d", &n, &m);
  int hx, hy, ex, ey;
  scanf("%d %d %d %d", &hy, &hx, &ey, &ex);

  for (int y = 1; y <= n; ++y)
  {
    for (int x = 1; x <= m; ++x)
    {
      scanf("%d", &map[y][x]);
      check[y][x][1] = check[y][x][0] = INF;
    }
  }

  int f = 0, r = 0;
  q[r][X] = hx;
  q[r][Y] = hy;
  q[r][M] = 1;
  q[r++][T] = 0;

  int ret = -1;
  check[hy][hx][1] = 0;

  // 0 : x, 1 : y, 2 : time, 3 : magic
  while (f != r)
  {
    int now[4] = { q[f][0], q[f][1], q[f][2], q[f++][3] };

    if (now[X] == ex && now[Y] == ey)
    {
      ret = now[T];
      break;
    }
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = now[X] + dx[dir];
      int ny = now[Y] + dy[dir];
      if (map[ny][nx])
      {
        if (now[M] && check[ny][nx][0] > now[T])
        {
          check[ny][nx][0] = now[T];
          q[r][X] = nx;
          q[r][Y] = ny;
          q[r][M] = 0;
          q[r++][T] = now[T] + 1;
        }
      }
      else
      {
        if (check[ny][nx][now[M]] > now[T])
        {
          check[ny][nx][0] = check[ny][nx][now[M]] = now[T];
          q[r][X] = nx;
          q[r][Y] = ny;
          q[r][M] = now[M];
          q[r++][T] = now[T] + 1;
        }
      }
    }
  }

  printf("%d\n", ret);
  return 0;
}

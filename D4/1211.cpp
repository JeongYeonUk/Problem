#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

int map[100][100];
int check[100][100];
bool flag;
int temp;
const int dx[] = { 1,-1,0 };
const int dy[] = { 0,0,1 };
void init()
{
  for (int i = 0; i < 100; ++i)
  {
    for (int j = 0; j < 100; ++j)
    {
      map[i][j] = 0;
      check[i][j] = 0;
    }
  }
}

void solve(int y, int x, int count)
{
  if (y == 99)
  {
    flag = true;
    temp = count;
    return;
  }
  check[y][x] = 1;
  for (int i = 0; i < 3; ++i)
  {
    if (flag) break;
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx && nx < 100 && 0 <= ny && ny < 100)
    {
      if (!check[ny][nx] && map[ny][nx])
      {
        check[ny][nx] = 1;
        solve(ny, nx, count + 1);
      }
    }
  }
  check[y][x] = 0;
  return;
}

int main()
{
  freopen("input.txt", "r", stdin);

  for (int cases = 1; cases <= 10; ++cases)
  {
    init();
    int T; scanf("%d", &T);
    for (int i = 0; i < 100; ++i)
    {
      for (int j = 0; j < 100; ++j)
      {
        scanf("%d", &map[i][j]);
      }
    }
    int ans = -1;
    int min = 987654321;
    for (int i = 0; i < 100; ++i)
    {
      if (!map[0][i]) continue;
      flag = false;
      temp = 0;
      solve(0,i, 0);
      if (min > temp)
      {
        if (ans < i)
        {
          min = temp;
          ans = i;
        }
      }
    }
    printf("#%d %d\n", T, ans);
  }

  return 0;
}

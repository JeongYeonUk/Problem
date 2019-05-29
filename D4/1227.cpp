#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

int map[100][100];
int check[100][100];
bool flag;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

void init()
{
  for (int i = 0; i < 100; ++i)
  {
    for (int j = 0; j < 100; ++j)
    {
      map[i][j] = check[i][j] = 0;
    }
  }
}

void solve(int y, int x)
{
  if (map[y][x] == 3)
  {
    flag = true;
    return;
  }
  if (flag)
  {
    return;
  }
  check[y][x] = 1;
  for (int i = 0; i < 4; ++i)
  {
    if (flag) break;
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (0 <= nx && nx < 100 && 0 <= ny && ny < 100)
    {
      if (!check[ny][nx] && (!map[ny][nx] || map[ny][nx] == 3))
      {
        check[ny][nx] = 1;
        solve(ny, nx);
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
    flag = false;
    int T; scanf("%d", &T);
    int start_x = 0, start_y = 0;
    for (int i = 0; i < 100; ++i)
    {
      for (int j = 0; j < 100; ++j)
      {
        scanf("%1d", &map[i][j]);
        if (map[i][j] == 2)
        {
          start_x = j;
          start_y = i;
        }
      }
    }
    solve(start_y, start_x);
    printf("#%d ", T);
    if (flag)
      printf("1\n");
    else
      printf("0\n");    
  }
  return 0;
}

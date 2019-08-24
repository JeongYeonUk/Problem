#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int map[2001][2001];
bool visit[2001][2001];
int N;

void dfs(int y, int x)
{
  if (0 > y || 0 > x || 2001 <= y || 2001 <= x)
    return;
  if (map[y][x] == 2 || map[y][x] == 0)
    return;
  map[y][x] = 2;
  for (int i = 0; i < 4; ++i)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    dfs(ny, nx);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 = (x1 + 500) * 2;
    x2 = (x2 + 500) * 2;
    y1 = (y1 + 500) * 2;
    y2 = (y2 + 500) * 2;
    for (int i = x1; i <= x2; ++i)
    {
      map[y1][i] = 1;
      map[y2][i] = 1;
    }
    for (int i = y1; i <= y2; ++i)
    {
      map[i][x1] = 1;
      map[i][x2] = 1;
    }
  }

  int ret = 0;
  for (int i = 0; i < 2001; ++i)
  {
    for (int j = 0; j < 2001; ++j)
    {
      if (map[i][j] == 1)
      {
        dfs(i, j);
        ret++;
      }
    }
  }

  if (map[1000][1000] == 2)
    ret--;

  cout << ret << '\n';

  return 0;
}

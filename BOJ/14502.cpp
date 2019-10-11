#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct INFO
{
  int y, x;
};

int map[8][8];
int n, m;
int ans;

int bfs()
{
  queue<INFO> q;
  int tmap[8][8] = { 0, };
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < m; ++x)
    {
      tmap[y][x] = map[y][x];
      if (map[y][x] == 2)
      {
        q.push({ y,x });
      }
    }
  }
  int ret = 0;
  while (!q.empty())
  {
    INFO cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      INFO next;
      next.y = cur.y + dy[dir];
      next.x = cur.x + dx[dir];
      if (next.x < 0 || next.y < 0 || next.x >= m || next.y >= n)
        continue;
      if (tmap[next.y][next.x] == 0)
      {
        q.push({ next.y, next.x });
        tmap[next.y][next.x] = 2;
      }
    }
  }
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < m; ++x)
    {
      if (!tmap[y][x])
        ret++;
    }
  }
  return ret;
}

void solve(int sy, int sx, int cnt)
{
  if (cnt == 3)
  {
    int candi = bfs();
    if (ans < candi)
      ans = candi;
    return;
  }
  for (int y = sy; y < n; ++y)
  {
    for (int x = sx; x < m; ++x)
    {
      if (map[y][x] == 0)
      {
        map[y][x] = 1;
        solve(y, x, cnt + 1);
        map[y][x] = 0;
      }
    }
    sx = 0;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n >> m;
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < m; ++x)
    {
      cin >> map[y][x];
    }
  }

  ans = 0;
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < m; ++x)
    {
      if (map[y][x] == 0)
      {
        map[y][x] = 1;
        solve(y, x, 1);
        map[y][x] = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

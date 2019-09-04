#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

struct INFO
{
  int rx, ry, bx, by, count;
};

char map[10][11];
INFO start;

int bfs()
{
  const int dx[] = { 1,0,-1,0 };
  const int dy[] = { 0,1,0,-1 };
  int visit[10][10][10][10] = { 0, };
  queue<INFO> q;
  q.push(start);
  visit[start.ry][start.rx][start.by][start.bx] = 1;
  int ret = -1;
  while (!q.empty())
  {
    INFO cur = q.front(); q.pop();
    if (cur.count > 10) break;
    if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O')
    {
      ret = cur.count;
      break;
    }
    for (int dir = 0; dir < 4; ++dir)
    {
      int next_rx = cur.rx;
      int next_ry = cur.ry;
      int next_bx = cur.bx;
      int next_by = cur.by;
      while (true)
      {
        if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O')
        {
          next_ry += dy[dir], next_rx += dx[dir];
        }
        else
        {
          if (map[next_ry][next_rx] == '#')
          {
            next_ry -= dy[dir], next_rx -= dx[dir];
          }
          break;
        }
      }
      while (true)
      {
        if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
        {
          next_by += dy[dir], next_bx += dx[dir];
        }
        else
        {
          if (map[next_by][next_bx] == '#')
          {
            next_by -= dy[dir], next_bx -= dx[dir];
          }
          break;
        }
      }
      if (next_ry == next_by && next_rx == next_bx) {
        if (map[next_ry][next_rx] != 'O') {
          int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
          int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
          if (red_dist > blue_dist) {
            next_ry -= dy[dir], next_rx -= dx[dir];
          }
          else {
            next_by -= dy[dir], next_bx -= dx[dir];
          }
        }
      }
      if (!visit[next_ry][next_rx][next_by][next_bx]) {
        visit[next_ry][next_rx][next_by][next_bx] = 1;
        INFO next;
        next.ry = next_ry;
        next.rx = next_rx;
        next.by = next_by;
        next.bx = next_bx;
        next.count = cur.count + 1;
        q.push(next);
      }
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, m; cin >> n >> m;
  
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < m; ++x)
    {
      cin >> map[y][x];
      if (map[y][x] == 'R')
      {
        start.rx = x, start.ry = y;
      }
      if (map[y][x] == 'B')
      {
        start.bx = x, start.by = y;
      }
    }
  }
  start.count = 0;
  int ret = bfs();
  cout << ret << '\n';

  return 0;
}

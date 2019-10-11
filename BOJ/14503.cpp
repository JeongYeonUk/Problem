#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = {0,1,0,-1 };
const int dy[] = { -1,0,1,0 };

struct ROBOT
{
  int y, x, dir;
};

int n, m;
int map[50][50];
ROBOT robot;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n >> m;
  cin >> robot.y >> robot.x >> robot.dir;

  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < m; ++x)
    {
      cin >> map[y][x];
    }
  }

  queue<ROBOT> q;
  q.push(robot);
  int ret = 0;
  while (!q.empty())
  {
    ROBOT cur = q.front(); q.pop();
    if (map[cur.y][cur.x] == 0)
    {
      map[cur.y][cur.x] = 2;
      ret++;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
      ROBOT next;
      next.dir = (cur.dir + 3 - dir) % 4;
      next.y = cur.y + dy[next.dir];
      next.x = cur.x + dx[next.dir];
      if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n
        || map[next.y][next.x] != 0)
        continue;

      q.push(next);
      break;
    }

    if (q.empty())
    {
      ROBOT next;
      next.dir = cur.dir;
      next.y = cur.y + dy[(next.dir + 2) % 4];
      next.x = cur.x + dx[(next.dir + 2) % 4];

      if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n
        || map[next.y][next.x] == 1)
        break;

      q.push(next);
    }
  }
  cout << ret << endl;
  return 0;
}

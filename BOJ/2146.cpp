#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct INFO {
  int y, x;
};

int a[100][100];
int g[100][100];
int d[100][100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n; cin >> n;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> a[y][x];
    }
  }
  int cnt = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (a[y][x] == 1 && g[y][x] == 0) {
        g[y][x] = ++cnt;
        queue<INFO> q;
        q.push({ y,x });
        while (!q.empty()) {
          INFO cur = q.front(); q.pop();
          for (int dir = 0; dir < 4; ++dir) {
            INFO next;
            next.y = cur.y + dy[dir];
            next.x = cur.x + dx[dir];
            if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= n) {
              continue;
            }
            if (a[next.y][next.x] == 1 && g[next.y][next.x] == 0) {
              g[next.y][next.x] = cnt;
              q.push({ next.y,next.x });
            }
          }
        }
      }
    }
  }
  queue<INFO> q;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      d[y][x] = -1;
      if (a[y][x] == 1) {
        q.push({ y,x });
        d[y][x] = 0;
      }
    }
  }
  while (!q.empty()) {
    INFO cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      INFO next;
      next.y = cur.y + dy[dir];
      next.x = cur.x + dx[dir];
      if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= n) {
        continue;
      }
      if (d[next.y][next.x] == -1) {
        d[next.y][next.x] = d[cur.y][cur.x] + 1;
        g[next.y][next.x] = g[cur.y][cur.x];
        q.push({ next.y,next.x });
      }
    }
  }
  int ans = -1;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
          continue;
        }
        if (g[y][x] != g[ny][nx]) {
          if (ans == -1 || ans > d[y][x] + d[ny][nx]) {
            ans = d[y][x] + d[ny][nx];
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

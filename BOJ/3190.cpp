#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int HEAD = 1;
const int TAIL = 2;
const int APPLE = 3;

struct INFO{
  int x;
  char c;
};

struct POINT {
  int x, y;
  POINT(int y = 0, int x = 0) : y(y), x(x){}
};

int map[101][101];
INFO info[100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int n, k; cin >> n >> k;

  for (int i = 0; i < k; ++i)  {
    int r, c; cin >> r >> c;
    map[r][c] = APPLE;
  }
  int l; cin >> l;
  for (int i = 0; i < l; ++i) {
    int x; char c; cin >> x >> c;
    info[i].x = x; info[i].c = c;
  }

  const int dx[] = { 1,0,-1,0 };
  const int dy[] = { 0,1,0,-1 };
  int time = 0;
  int cx = 1, cy = 1;
  int dir = 0;
  map[cy][cx] = HEAD;
  queue<POINT> q;
  while (true){
    for (int i = 0; i < l; ++i) {
      if (time < info[i].x)
        break;
      if (time == info[i].x) {
        if (dir == 0) {
          if (info[i].c == 'L') {
            dir = 3;
          }
          else {
            dir = 1;
          }
        }
        else if (dir == 1) {
          if (info[i].c == 'L') {
            dir = 0;
          }
          else {
            dir = 2;
          }
        }
        else if (dir == 2) {
          if (info[i].c == 'L') {
            dir = 1;
          }
          else {
            dir = 3;
          }
        }
        else if (dir == 3) {
          if (info[i].c == 'L') {
            dir = 2;
          }
          else {
            dir = 0;
          }
        }
      }
    }
    int ny = cy + dy[dir];
    int nx = cx + dx[dir];
    time++;
    if (0 >= ny || 0 >= nx || ny > n || nx > n)
      break;
    if (map[ny][nx] == TAIL)
      break;
    if (map[ny][nx] == APPLE) {
      q.push({ cy,cx });
      map[cy][cx] = TAIL;
      map[ny][nx] = HEAD;
      cy = ny, cx = nx;
    }
    else {
      if (!q.empty()) {
        POINT ePoint = q.front(); q.pop();
        map[ePoint.y][ePoint.x] = 0;
        map[cy][cx] = TAIL;
        map[ny][nx] = HEAD;
        q.push({ cy,cx });
        cy = ny, cx = nx;
      }
      else {
        map[cy][cx] = 0;
        map[ny][nx] = HEAD;
        cy = ny, cx = nx;
      }
    }
  }
  cout << time << '\n';
  return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

const int dx[] = { 1,0,-1,0};
const int dy[] = { 0,1,0,-1};

struct INFO {
  int y, x;
  INFO(int y = 0, int x = 0) : y(y), x(x){}
};

inline int min(int a, int b) {
  return a > b ? b : a;
}

int map[10][10];
int tmp[10][10];
INFO seed[3];
int N;
int ans;

int bfs() {  
  int tmp2[10][10] = { 0, };
  int ret = 0;
  for (int i = 0; i < 3; ++i) {
    INFO cur = seed[i];
    ret += map[cur.y][cur.x];
    tmp2[cur.y][cur.x] = 1;
    for (int dir = 0; dir < 4; ++dir) {
      INFO next;
      next.y = cur.y + dy[dir];
      next.x = cur.x + dx[dir];
      if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) {
        return INF;
      }
      if (tmp2[next.y][next.x] == 1) {
        return INF;
      }
      tmp2[next.y][next.x] = 1;
      ret += map[next.y][next.x];
    }
  }
  return ret;
}

void solve(int sy, int sx, int cnt) {
  if (cnt == 3) {
    ans = min(ans, bfs());
    return;
  }

  for (int y = sy; y < N; ++y) {
    for (int x = sx; x < N; ++x) {
      if (!tmp[y][x]) {
        tmp[y][x] = 1;
        seed[cnt] = { y,x };
        solve(y, x, cnt + 1);
        tmp[y][x] = 0;
        seed[cnt] = { 0,0 };
      }
    }
    sx = 1;
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      cin >> map[y][x];
    }
  }

  ans = INF;
  solve(1, 1, 0);

  cout << ans << endl;

  return 0;
}

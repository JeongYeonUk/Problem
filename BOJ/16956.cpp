#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct INFO {
  int y, x;
  INFO(int y = 0, int x = 0) : y(y),x(x){}
};

char map[500][501];
INFO wolf[500*500];
int R, C;
int wolf_idx;

bool solve() {
  for (int i = 0; i <= wolf_idx; ++i) {
    INFO cur = wolf[i];
    for (int dir = 0; dir < 4; ++dir) {
      INFO next;
      next.y = cur.y + dy[dir];
      next.x = cur.x + dx[dir];
      if (next.x < 0 || next.y < 0 || next.x >= C || next.y >= R)
        continue;
      if (map[next.y][next.x] == 'S')
        return false;
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> R >> C;
  wolf_idx = -1;
  for (int y = 0; y < R; ++y) {
    for (int x = 0; x < C; ++x) {
      cin >> map[y][x];
      if (map[y][x] == '.')
        map[y][x] = 'D';
      if (map[y][x] == 'W')
        wolf[++wolf_idx] = { y,x };
    }
  }

  if (solve()) {
    cout << "1\n";
    for (int y = 0; y < R; ++y) {
      for (int x = 0; x < C; ++x) {
        cout << map[y][x];
      }
      cout << endl;
    }
  }
  else {
    cout << "0\n";
  }

  return 0;
}

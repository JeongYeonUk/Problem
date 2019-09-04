#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
int n, ret;
struct BOARD
{
  int map[20][20];

  void rotate()
  {
    int temp[20][20];
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        temp[y][x] = map[n - x - 1][y];
      }
    }
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        map[y][x] = temp[y][x];
      }
    }
  }

  int get_max() {
    int ret = 0;
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (ret < map[y][x])
          ret = map[y][x];
      }
    }
    return ret;
  }

  void up() {
    int temp[20][20];
    for (int x = 0; x < n; ++x) {
      int flag = 0, target = -1;
      for (int y = 0; y < n; ++y) {
        if (map[y][x] == 0) {
          continue;
        }
        if (flag == 1 && map[y][x] == temp[target][x]) {
          temp[target][x] *= 2, flag = 0;
        }
        else {
          temp[++target][x] = map[y][x], flag = 1;
        }
      }
      for (++target; target < n; ++target) {
        temp[target][x] = 0;
      }
    }
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        map[y][x] = temp[y][x];
      }
    }
  }
};

void dfs(BOARD cur, int count)
{
  if (count == 5)
  {
    int candi = cur.get_max();
    if (ret < candi)
      ret = candi;
    return;
  }
  for (int dir = 0; dir < 4; ++dir)
  {
    BOARD next = cur;
    next.up();
    dfs(next, count + 1);
    cur.rotate();
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  BOARD board;
  cin >> n;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> board.map[y][x];
    }
  }
  ret = 0;
  dfs(board, 0);
  cout << ret << '\n';
  return 0;
}

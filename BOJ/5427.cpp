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

char building[1000][1001];
int cache[1000][1001];
int w, h;
INFO start;

int bfs(queue<INFO> fire) {
  memset(cache, 0, sizeof(cache));
  int ret = -1;

  queue<INFO> person;
  person.push(start);

  cache[start.y][start.x] = 1;
  while (!person.empty()) {
    int fireSize = (int)fire.size();
    for (int i = 0; i < fireSize; ++i) {
      INFO curFire = fire.front(); fire.pop();
      for (int dir = 0; dir < 4; ++dir) {
        INFO next;
        next.y = curFire.y + dy[dir];
        next.x = curFire.x + dx[dir];
        if (next.y < 0 || next.x < 0 || next.x >= w || next.y >= h) {
          continue;
        }
        if (building[next.y][next.x] == '#') {
          continue;
        }
        if (building[next.y][next.x] == '.' || building[next.y][next.x] == '@') {
          building[next.y][next.x] = '*';
          fire.push({ next.y,next.x });
        }
      }
    }

    int personSize = (int)person.size();
    for (int i = 0; i < personSize; ++i) {
      INFO curPerson = person.front(); person.pop();
      for (int dir = 0; dir < 4; ++dir) {
        INFO next;
        next.y = curPerson.y + dy[dir];
        next.x = curPerson.x + dx[dir];
        if (next.x < 0 || next.y < 0 || next.x >= w || next.y >= h) {
          return cache[curPerson.y][curPerson.x];
        }
        if (building[next.y][next.x] == '#' || building[next.y][next.x] == '*') {
          continue;
        }
        if (building[next.y][next.x] == '.' && cache[next.y][next.x] == 0) {
          building[next.y][next.x] = '@';
          person.push({ next.y,next.x });
          cache[next.y][next.x] = cache[curPerson.y][curPerson.x] + 1;
        }
      }
    }    
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    queue<INFO> fire;
    cin >> w >> h;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        cin >> building[y][x];
        if (building[y][x] == '*') {
          fire.push({ y,x });
        }
        if (building[y][x] == '@') {
          start = { y,x };
        }
      }
    }

    int ret = bfs(fire);
    if (ret == -1) {
      cout << "IMPOSSIBLE\n";
    }
    else {
      cout << ret << endl;
    }
  }

  return 0;
}

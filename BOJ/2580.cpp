#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
int R, C;

char map[21][21];
bool visit[26];
int ret;

void solve(int sy, int sx,int depth)
{
  for (int i = 0; i < 4; ++i)
  {
    int ny = sy + dy[i];
    int nx = sx + dx[i];
    if (0 <= nx && nx < C && 0 <= ny && ny < R)
    {
      if (!visit[map[ny][nx] - 'A'])
      {
        visit[map[ny][nx] - 'A'] = true;
        solve(ny, nx, depth + 1);
        visit[map[ny][nx] - 'A'] = false;
      }
    }
  }
  ret = max(ret, depth);
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> R >> C;
  for (int i = 0; i < R; ++i)
  {
    cin >> map[i];
  }

  visit[map[0][0] - 'A'] = true;
  solve(0,0,1);

  cout << ret << '\n';

  return 0;
}

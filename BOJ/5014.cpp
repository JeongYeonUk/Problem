#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX = 1000000;

struct m
{
  int floor;
  int button;
};

bool visit[MAX];
int F, S, G, U, D;

int bfs()
{
  queue<m> q;
  q.push({ S,0 });
  visit[S] = true;
  while (!q.empty())
  {
    int cur = q.front().floor;
    int but = q.front().button;
    q.pop();

    if (cur == G)
      return but;

    // U
    if (cur + U <= MAX && !visit[cur + U])
    {
      visit[cur + U] = true;
      q.push({ cur + U, but + 1 });
    }
    // D
    if (cur - D > 0 && !visit[cur - D])
    {
      visit[cur - D] = true;
      q.push({ cur - D, but + 1 });
    }
  }
  return INF;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> F >> S >> G >> U >> D;

  int ret = bfs();

  if (ret == INF)
    cout << "use the stairs\n";
  else
    cout << ret << '\n';

  return 0;
}

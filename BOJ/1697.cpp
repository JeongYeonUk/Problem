#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
bool visit[100001];
queue<int> q;

int bfs(int n, int m)
{
  int time = 0;
  q.push(n);
  while (1)
  {
    int size = q.size();
    for (int i = 0; i < size; ++i)
    {
      n = q.front(); q.pop();
      if (n == m)
        return time;
      if (n > 0 && visit[n - 1] == 0)
      {
        q.push(n - 1);
        visit[n - 1] = 1;
      }
      if (n < 100000 && visit[n + 1] == 0)
      {
        q.push(n + 1);
        visit[n + 1] = 1;
      }
      if (n * 2 <= 100000 && visit[n * 2] == 0)
      {
        q.push(n * 2);
        visit[n * 2] = 1;
      }
    }
    time++;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N, K; cin >> N >> K;
  cout << bfs(N, K);
  return 0;
}

#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX = 10000;

struct s
{
  int num;
  string cur;
};

int start, dest;
bool visit[MAX];
int N;

string bfs()
{
  queue<s> q;
  q.push({ start,"" });
  visit[start] = true;
  while (!q.empty())
  {
    int num = q.front().num;
    string change = q.front().cur;
    q.pop();

    if (num == dest)
      return change;
    int cur = (num * 2) % MAX;
    if (!visit[cur])
    {
      visit[cur] = true;
      q.push({ cur, change + "D" });
    }
    cur = (num - 1) < 0 ? 9999 : num - 1;
    if (!visit[cur])
    {
      visit[cur] = true;
      q.push({ cur, change + "S"});
    }
    cur = (num % 1000) * 10 + (num / 1000);
    if (!visit[cur])
    {
      visit[cur] = true;
      q.push({ cur, change + "L" });
    }
    cur = (num % 10) * 1000 + (num / 10);
    if (!visit[cur])
    {
      visit[cur] = true;
      q.push({ cur,change + "R" });
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int cases = 0; cases < N; ++cases)
  {
    cin >> start >> dest;
    memset(visit, 0, sizeof(visit));
    cout << bfs() << '\n';
  }

  return 0;
}

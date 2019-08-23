#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int target = 123456789;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int start = 0;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      int num; cin >> num;
      if (num == 0) num = 9;
      start = start * 10 + num;
    }
  }

  queue<int> q;
  map<int, int> visit;
  q.push(start);
  visit[start] = 0;

  while (!q.empty())
  {
    int cur = q.front();
    string s = to_string(cur);
    q.pop();

    if (cur == target) break;

    int z = s.find('9');
    int y = z / 3;
    int x = z % 3;

    for (int i = 0; i < 4; ++i)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (0 <= ny && ny < 3 && 0 <= nx && nx < 3)
      {
        string tmp = s;
        swap(tmp[y * 3 + x], tmp[ny * 3 + nx]);
        int next = stoi(tmp);
        if (!visit.count(next))
        {
          visit[next] = visit[cur] + 1;
          q.push(next);
        }
      }
    }
  }
  if (!visit.count(target))
    cout << "-1\n";
  else
    cout << visit[target] << '\n';
  return 0;
}

#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 10000;

int prime[MAX_N];

void era()
{
  prime[0] = prime[1] = -1;
  for (int i = 2; i < MAX_N; ++i)
    prime[i] = i;
  for (int i = 2; i*i < MAX_N; ++i)
  {
    if (prime[i] == i)
    {
      for (int j = i * i; j < MAX_N; j += i)
      {
        if (prime[j] == j)
          prime[j] = i;
      }
    }
  }
}

int start, dest;
int d[MAX_N];

int bfs()
{
  memset(d, 0, sizeof(d));
  queue<int> q;
  q.push(start);
  d[start] = 1;
  while (!q.empty())
  {
    int cur = q.front(); q.pop();
    if (cur == dest)
      return d[cur] - 1;

    int digit[4] = { (cur / 1000),
      (cur / 100) % 10,
    (cur / 10) % 10,
    (cur % 10)
    };

    for (int i = 0; i < 4; ++i)
    {
      if (i == 0)
      {
        for (int j = 1; j < 10; ++j)
        {
          int next = 0;
          for (int k = 0; k < 4; ++k)
          {
            if (i != k)
              next += digit[k] * pow(10, 3 - k);
            else
              next += j * pow(10, 3 - k);
          }
          if (prime[next] == next && d[next] == 0)
          {
            d[next] = d[cur] + 1;
            q.push(next);
          }
        }
      }
      else
      {
        for (int j =0; j < 10; ++j)
        {
          int next = 0;
          for (int k = 0; k < 4; ++k)
          {
            if (i != k)
              next += digit[k] * pow(10, 3 - k);
            else
              next += j * pow(10, 3 - k);
          }
          if (prime[next] == next && d[next] == 0)
          {
            d[next] = d[cur] + 1;
            q.push(next);
          }
        }
      }
    }
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  era();
  for (int i = 0; i < T; ++i)
  {
    cin >> start >> dest;
    int ret = bfs();
    if (ret == -1)
      cout << "Impossible" << '\n';
    else
      cout << ret << '\n';
  }

  return 0;
}

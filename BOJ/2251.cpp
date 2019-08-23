#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int A, B, C;
vector<int>vec;
struct water
{
  int a, b, c;
};
water w;

bool visit[201][201][201];

void bfs()
{
  water start = w;
  queue<water> q;
  q.push(w);
  visit[w.a][w.b][w.c] = true;
  while (!q.empty())
  {

    water cur = q.front();
    q.pop();

    if (cur.a == 0)
      vec.push_back(cur.c);

    // C -> A
    if (cur.a < A && cur.c != 0)
    {
      if (cur.c - (A - cur.a) <= 0)
      {
        if (!visit[cur.a + cur.c][cur.b][0])
        {
          visit[cur.a + cur.c][cur.b][0] = true;
          q.push({ cur.a + cur.c, cur.b,0 });
          //cout << "C -> A" << ' ';
          //cout << cur.a + cur.c << ' ' << cur.b << ' ' << 0 << '\n';
        }
      }
      else
      {
        if (!visit[cur.a + (A - cur.a)][cur.b][cur.c - (A - cur.a)])
        {
          visit[cur.a + (A - cur.a)][cur.b][cur.c - (A - cur.a)] = true;
          q.push({ cur.a + (A - cur.a), cur.b, cur.c - (A - cur.a) });
          //cout << "C -> A" << ' ';
          //cout << cur.a + (A - cur.a) << ' ' << cur.b << ' ' << cur.c - (A - cur.a) << '\n';
        }
      }
    }
    // C -> B
    if (cur.b < B && cur.c != 0)
    {
      if (cur.c - (B - cur.b) <= 0)
      {
        if (!visit[cur.a][cur.b + cur.c][0])
        {
          visit[cur.a][cur.b + cur.c][0] = true;
          q.push({ cur.a,cur.b + cur.c, 0 });
          //cout << "C -> B" << ' ';
          //cout << cur.a << ' ' << cur.b + cur.c << ' ' << 0 << '\n';
        }
      }
      else
      {
        if (!visit[cur.a][cur.b + (B - cur.b)][cur.c - (B - cur.b)])
        {
          visit[cur.a][cur.b + (B - cur.b)][cur.c - (B - cur.b)] = true;
          q.push({ cur.a, cur.b + (B - cur.b), cur.c - (B - cur.b) });
          //cout << "C -> B" << ' ';
          //cout << cur.a << ' ' << cur.b + (B - cur.b) << ' ' << cur.c - (B - cur.b) << '\n';
        }
      }
    }
    // A -> B
    if(cur.b < B && cur.a != 0)
    {
      if (cur.a - (B - cur.b) <= 0)
      {
        if (!visit[0][cur.b + cur.a][cur.c])
        {
          visit[0][cur.b + cur.a][cur.c] = true;
          q.push({ 0,cur.b + cur.a,cur.c });
          //cout << "A -> B" << ' ';
          //cout << 0 << ' ' << cur.b + cur.a << ' ' << cur.c << '\n';
        }
      }
      else
      {
        if (!visit[cur.a - (B - cur.b)][cur.b + (B - cur.b)][cur.c])
        {
          visit[cur.a - (B - cur.b)][cur.b + (B - cur.b)][cur.c] = true;
          q.push({ cur.a - (B - cur.b), cur.b + (B - cur.b), cur.c });
          //cout << "A -> B" << ' ';
          //cout << cur.a - (B - cur.b) << ' ' << cur.b + (B - cur.b) << ' ' << cur.c << '\n';
        }
      }
    }
    // B -> A
    if (cur.a < A && cur.b != 0)
    {
      if (cur.b - (A - cur.a) <= 0)
      {
        if (!visit[cur.a + cur.b][0][cur.c])
        {
          visit[cur.a + cur.b][0][cur.c] = true;
          q.push({ cur.a + cur.b,0, cur.c });
          //cout << "B -> A" << ' ';
          //cout << cur.a + cur.b << ' ' << 0 << ' ' << cur.c << '\n';
        }
      }
      else
      {
        if (!visit[cur.a + (A - cur.a)][cur.b - (A - cur.a)][cur.c])
        {
          visit[cur.a + (A - cur.a)][cur.b - (A - cur.a)][cur.c] = true;
          q.push({ cur.a + (A - cur.a), cur.b - (A - cur.a), cur.c });
          //cout << "B -> A" << ' ';
          //cout << cur.a + (A - cur.a) << ' ' << cur.b - (A - cur.a) << ' ' << cur.c << '\n';
        }
      }
    }
    // A -> C
    if (cur.c < C && cur.a != 0)
    {
      if (cur.a - (C - cur.c) <= 0)
      {
        if (!visit[0][cur.b][cur.a + cur.c])
        {
          visit[0][cur.b][cur.a + cur.c] = true;
          q.push({ 0,cur.b, cur.a + cur.c });
          //cout << "A -> C" << ' ';
          //cout << 0 << ' ' << cur.b << ' ' << cur.a + cur.c << '\n';
        }
      }
      else
      {
        if (!visit[cur.a - (C - cur.c)][cur.b][cur.c + (C - cur.c)])
        {
          visit[cur.a - (C - cur.c)][cur.b][cur.c + (C - cur.c)] = true;
          q.push({ cur.a - (C - cur.c), cur.b, cur.c + (C - cur.c) });
          //cout << "A -> C" << ' ';
          //cout << cur.a - (C - cur.c) << ' ' << cur.b << ' ' << cur.c + (C - cur.c) << '\n';
        }
      }
    }
    // B -> C
    if (cur.c < C && cur.b != 0)
    {
      if (cur.b - (C - cur.c) <= 0)
      {
        if (!visit[cur.a][0][cur.b + cur.c])
        {
          visit[cur.a][0][cur.b + cur.c] = true;
          q.push({ cur.a,0, cur.b + cur.c });
          //cout << "B -> C" << ' ';
         // cout << cur.a << ' ' << 0 << ' ' << cur.b + cur.c << '\n';
        }
      }
      else
      {
        if (!visit[cur.a][cur.b - (C - cur.c)][cur.c + (C - cur.c)])
        {
          visit[cur.a][cur.b - (C - cur.c)][cur.c + (C - cur.c)] = true;
          q.push({ cur.a, cur.b - (C - cur.c), cur.c + (C - cur.c) });
          //cout << "B -> C" << ' ';
          //cout << cur.a << ' ' << cur.b - (C - cur.c) << ' ' << cur.c + (C - cur.c) << '\n';
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> A >> B >> C;

  w.a = w.b = 0;
  w.c = C;

  bfs();

  sort(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); ++i)
  {
    cout << vec[i] << ' ';
  }

  return 0;
}

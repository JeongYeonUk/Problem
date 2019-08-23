#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int N, M, K;
int Ans;
char map[100][100];
int d[100][100][80];

string dest;
int dest_len;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int dfs(int x, int y, int idx)
{
  int& ret = d[x][y][idx];
  if (ret != -1)
    return ret;
  if (idx >= dest_len)
    return 1;
  ret = 0;
  for (int i = 0; i < 4; ++i)
  {
    for (int k = 1; k <= K; ++k)
    {
      int ny = y + dy[i] * k;
      int nx = x + dx[i] * k;
      if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        continue;
      if (map[nx][ny] != dest[idx])
        continue;
      ret = ret + dfs(nx, ny, idx + 1);
    }
  }
  return ret;
}

void solution()
{
  char tmp = dest[0];
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
    {
      if (map[i][j] == tmp)
      {
        Ans = Ans + dfs(i, j, 1);
      }
    }
  }
  cout << Ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
    {
      cin >> map[i][j];
    }
  }
  cin >> dest;
  dest_len = dest.length();
  memset(d, -1, sizeof(d));
  solution();
  return 0;
}

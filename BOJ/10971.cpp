#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int arr[11][11];
int visit[11];
int N;
int ret;
int first;
void dfs(int node, int sum, int cnt)
{
  if (!visit[node])
  {
    visit[node] = 1;
    for (int i = 0; i < N; ++i)
    {
      if(arr[node][i] != 0)
        dfs(i, sum + arr[node][i], cnt + 1);
    }
    visit[node] = 0;
  }
  if (cnt == N && node == first)
  {
    ret = (ret == 0) ? sum : min(sum, ret);
    return;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cin >> arr[i][j];
    }
  }

  ret = INF;
  for (int i = 0; i < N; ++i)
  {
    memset(visit, 0, sizeof(visit));
    first = i;
    dfs(i, 0, 0);
  }

  cout << ret << '\n';

  return 0;
}

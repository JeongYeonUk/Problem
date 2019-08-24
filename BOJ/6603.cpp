#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int arr[13];
int lotto[6];
int K;

void dfs(int idx, int depth)
{
  if (depth == 6)
  {
    for (int i = 0; i < 6; ++i)
    {
      cout << lotto[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = idx; i < K; ++i)
  {
    lotto[depth] = arr[i];
    dfs(i + 1, depth + 1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  while (true)
  {
    cin >> K;
    if (K == 0) break;
    for (int i = 0; i < K; ++i)
    {
      cin >> arr[i];
    }
    dfs(0, 0);
    cout << '\n';
  }
  return 0;
}

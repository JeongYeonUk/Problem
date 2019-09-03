#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int arr[16][16];
int n, m, k;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n >> m >> k;  

  for (int i = 1; i <= m; ++i) arr[1][i] = 1;
  for (int i = 1; i <= n; ++i) arr[i][1] = 1;

  if (k == 0)
  {
    for (int i = 2; i <= n; ++i)
    {
      for (int j = 2; j <= m; ++j)
      {
        arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
      }
    }
    cout << arr[n][m] << '\n';
  }
  else
  {

    int y = ((k % m) == 0 ? (k / m) : (k / m) + 1);
    int x = ((k % m) == 0 ? m : k % m);
    for (int i = 2; i <= y; ++i)
    {
      for (int j = 2; j <= x; ++j)
      {
        arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
      }
    }

    for (int i = y; i <= n; ++i) arr[i][x] = arr[y][x];
    for (int i = x; i <= m; ++i) arr[y][i] = arr[y][x];

    for (int i = y + 1; i <= n; ++i)
    {
      for (int j = x + 1; j <= m; ++j)
      {
        arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
      }
    }
    cout << arr[n][m] << '\n';
  }

  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int arr[7][2];
int N, K;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  for (int i = 1; i <= N; ++i)
  {
    int s, y; cin >> s >> y;
    arr[y][s]++;
  }

  int ans = 0;
  for (int i = 1; i <= 6; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      if (!arr[i][j]) continue;
      int tmp = arr[i][j];
      while (true)
      {
        if (tmp <= 0)
          break;
        tmp -= K;
        ans++;
      }
    }   
  }

  cout << ans << '\n';

  return 0;
}

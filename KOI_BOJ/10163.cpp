#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int map[110][110];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  int sx, sy, width, height;
  for (int i = 1; i <= N; ++i)
  {
    cin >> sx >> sy >> width >> height;
    for (int y = sy; y < sy + height; ++y)
    {
      for (int x = sx; x < sx + width; ++x)
      {
        map[y][x] = i;
      }
    }
  }

  for (int i = 1; i <= N; ++i)
  {
    int ans = 0;
    for (int y = 0; y < 110; ++y)
    {
      for (int x = 0; x < 110; ++x)
      {
        if (map[y][x] == i)
        {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

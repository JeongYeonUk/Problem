#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MOD = 100000;
const int MAX_WH = 103;
int cache[MAX_WH][MAX_WH][2][2];
int W, H;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> W >> H;
  for (int w = 2; w <= W; ++w)
    cache[w][1][0][0] = 1;
  for (int h = 2; h <= H; ++h)
    cache[1][h][1][0] = 1;

  for (int w = 2; w <= W; ++w)
  {
    for (int h = 2; h <= H; ++h)
    {
      cache[w][h][0][0] = (cache[w - 1][h][0][0]
        + cache[w - 1][h][0][1]) % MOD;
      cache[w][h][0][1] = cache[w - 1][h][1][0];

      cache[w][h][1][0] = (cache[w][h - 1][1][0]
        + cache[w][h - 1][1][1]) % MOD;
      cache[w][h][1][1] = cache[w][h - 1][0][0];
    }
  }

  int ans = 0;
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      ans += cache[W][H][i][j];
      ans %= MOD;
    }
  }
  cout << ans << '\n';

  return 0;
}

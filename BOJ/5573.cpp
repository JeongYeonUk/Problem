#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_HW = 1001;

bool arr[MAX_HW][MAX_HW];
int cache[MAX_HW][MAX_HW];
int H, W, N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> H >> W >> N;
  for (int i = 1; i <= H; ++i)
  {
    for (int j = 1; j <= W; ++j)
    {
      cin >> arr[i][j];
    }
  }

  cache[1][1] = N;
  for (int i = 1; i <= H; ++i)
  {
    for (int j = 1; j <= W; ++j)
    {
      if (cache[i][j] % 2)
      {
        if (arr[i][j])
        {
          cache[i][j + 1] += cache[i][j] / 2 + 1;
          cache[i + 1][j] += cache[i][j] / 2;
        }
        else
        {
          cache[i][j + 1] += cache[i][j] / 2;
          cache[i + 1][j] += cache[i][j] / 2 + 1;
        }
      }
      else
      {
        arr[i][j] = !arr[i][j];
        cache[i][j + 1] += cache[i][j] / 2;
        cache[i + 1][j] += cache[i][j] / 2;
      }
    }
  }
  

  int i = 1, j = 1;
  while (i <= H && j <= W)
  {
    if (arr[i][j]) j++;
    else
      i++;
  }
  cout << i << ' ' << j << '\n';

  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 103;

ll cache[MAX_N][21];
ll arr[MAX_N];
int N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> arr[i];

  cache[1][arr[1]] = 1;

  for (int i = 2; i <= N; ++i)
  {
    for (int j = 0; j <= 20; ++j)
    {
      if (j + arr[i] <= 20)
        cache[i][j + arr[i]] += cache[i - 1][j];
      if (j - arr[i] >= 0)
        cache[i][j - arr[i]] += cache[i - 1][j];
    }
  }

  cout << cache[N-1][arr[N]] << '\n';

  return 0;
}

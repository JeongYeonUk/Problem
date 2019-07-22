#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
int cache[1001][1001];
int N, K;

int bino(int n, int r)
{
  if (n == r || r == 0)
    return 1;
  int& ret = cache[n][r];
  if (ret > 0) return ret;
  return ret = (bino(n - 1, r - 1) + bino(n - 1, r)) % 10007;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> N >> K;
  cout << bino(N, K) % 10007 << '\n';
  return 0;
}

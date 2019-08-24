#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 10007;

int d[1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  d[0] = 0;
  d[1] = 1;
  d[2] = 3;
  for (int i = 3; i <= N; ++i)
  {
    d[i] = (d[i - 1] + 2 * d[i - 2]) % MOD;
  }

  cout << d[N] << '\n';

  return 0;
}

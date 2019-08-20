#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 201;
const int MOD = 1000000000;

int d[MAX_N][MAX_N];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N, K; cin >> N >> K;
  for (int i = 0; i <= N; ++i)
  {
	  d[1][i] = 1;
  }
  for (int k = 2; k <= K; ++k)
  {
	  for (int n = 0; n <= N; ++n)
	  {
		  for (int l = 0; l <= n; ++l)
		  {
			  d[k][n] += d[k - 1][n - l];
			  d[k][n] %= MOD;
		  }
	  }
  }
  cout << d[K][N] << '\n';

  return 0;
}

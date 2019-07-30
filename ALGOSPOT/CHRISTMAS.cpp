#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MOD = 20091101;

int waysToBuy(const vector<int>& psum, int K)
{
  int ret = 0;
  vector<ll> count(K, 0);
  for (int i = 0; i < psum.size(); ++i)
  {
    count[psum[i]]++;
  }

  for (int i = 0; i < K; ++i)
    if (count[i] >= 2)
      ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
  return ret;
}

int maxBuys(const vector<int>& psum, int K)
{
  vector<int> result(psum.size(), 0);
  vector<int> previous(K, -1);
  for (int i = 0; i < psum.size(); ++i)
  {
    if (i > 0)
      result[i] = result[i - 1];
    else
      result[i] = 0;

    int loc = previous[psum[i]];
    if (loc != -1)
      result[i] = max(result[i], result[loc] + 1);
    previous[psum[i]] = i;
  }
  return result.back();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
      cin >> v[i];

    vector<int> psum(N + 1);
    psum[0] = 0;
    for (int i = 1; i <= N; ++i)
      psum[i] = (psum[i - 1] + v[i - 1]) % K;

    cout << waysToBuy(psum, K) << ' ' << maxBuys(psum, K) << '\n';
  }

  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

#define endl '\n'
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 100001;
int d[MAX_N];
int N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    d[i] = i;
  }
  for (int i = 2; i <= N; ++i)
  {
    for (int j = 2; j * j <= i; ++j)
    {
      d[i] = min(d[i], d[i - j*j] + 1);
    }
  }
  cout << d[N] << '\n';
  return 0;
}

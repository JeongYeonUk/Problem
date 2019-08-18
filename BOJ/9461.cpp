#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 101;

long long d[MAX_N];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  while (T--)
  {
    int N; cin >> N;
    d[1] = d[2] = d[3] = 1;
    d[4] = d[5] = 2;
    for (int i = 6; i <= N; ++i)
    {
      d[i] = d[i - 5] + d[i - 1];
    }
    cout << d[N] << '\n';
  }

  return 0;
}

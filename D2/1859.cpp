#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

long long value[MAX];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> value[i];

    long long ans = 0;
    int max = 0;
    for (int i = n - 1; i >= 0; --i)
    {
      if (max > value[i])
        ans += max - value[i];
      else
        max = value[i];
    }
    cout << '#' << cases << ' ' << ans << '\n';
  }

  return 0;
}

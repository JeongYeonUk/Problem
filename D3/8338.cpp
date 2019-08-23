#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10];
int d[10];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    memset(d, 0, sizeof(d));
    int N; cin >> N;
    for (int i = 0; i < N; ++i)
    {
      cin >> arr[i];
    }
    d[0] = arr[0];
    for (int i = 1; i < N; ++i)
    {
      d[i] = max(d[i - 1] + arr[i], d[i - 1] * arr[i]);
    }
    cout << '#' << cases << ' ' << d[N-1] << '\n';
  }

  return 0;
}

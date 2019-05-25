#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1001;

int arr[MAX];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    int N; cin >> N;
    for (int i = 1; i <= N; ++i)
    {
      cin >> arr[i];
    }
    int min = 987654321;
    for (int i = 1; i <= N; ++i)
    {
      int temp = abs(0 - arr[i]);
      if (min > temp)
        min = temp;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
      if (abs(arr[i]) == min)
        ans++;
    }
    cout << '#' << cases << ' ' << min << ' ' << ans << '\n';
  }

  return 0;
}

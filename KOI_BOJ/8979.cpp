#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

struct Data
{
  int gold, sliver, bronze;
};

Data arr[1001];
int N, K;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  for (int i = 1; i <= N; ++i)
  {
    int a; cin >> a;
    cin >> arr[a].gold >> arr[a].sliver >> arr[a].bronze;
  }

  int ans = 1;
  for (int i = 1; i <= N; ++i)
  {
    if (i == K)
      continue;
    if (arr[K].gold < arr[i].gold)
      ans++;
    else if (arr[K].gold == arr[i].gold)
    {
      if (arr[K].sliver < arr[i].sliver)
        ans++;
      else if (arr[K].sliver == arr[i].sliver)
      {
        if (arr[K].bronze < arr[i].bronze)
        {
          ans++;
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

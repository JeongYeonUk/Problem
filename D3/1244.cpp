#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string number;
int trade;
int ans;

void dfs(int cnt, int now)
{
  if (cnt == trade)
  {
    ans = max(ans, stoi(number));
    return;
  }
  for (int i = now; i < number.length(); ++i)
  {
    for (int j = i; j < number.length(); ++j)
    {
      if (i == j) continue;
      if (number[i] <= number[j])
      {
        swap(number[i], number[j]);
        dfs(cnt + 1, i);
        swap(number[i], number[j]);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    ans = 0;
    cin >> number;
    cin >> trade;
    dfs(0, 0);
    cout << '#' << cases << ' ' << ans << '\n';
  }
  return 0;
}

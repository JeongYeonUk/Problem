#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;
pii arr[4];

int solve(pii a, pii b, pii c)
{
  int op = a.first * b.second
    + b.first * c.second
    + c.first * a.second;
  op -= (a.second * b.first
    + b.second * c.first
    + c.second * a.first);

  if (op > 0)
    return -1;
  else if (op < 0)
    return 1;
  else
    return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (int i = 0; i < 4; ++i)
  {
    cin >> arr[i].first >> arr[i].second;
  }

  if (solve(arr[0], arr[1], arr[2])
    * solve(arr[0], arr[1], arr[3]) < 0)
    cout << "1\n";
  else
    cout << "0\n";

  return 0;
}

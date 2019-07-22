#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;

int solve(pii p1, pii p2, pii p3)
{
  int op = p1.first * p2.second
    + p2.first * p3.second
    + p3.first * p1.second;

  op -= (p1.second * p2.first
    + p2.second * p3.first
    + p3.second * p1.first);

  if (op > 0) return 1;
  else if (op < 0) return -1;
  else
    return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  pii P1, P2, P3;

  cin >> P1.first >> P1.second;
  cin >> P2.first >> P2.second;
  cin >> P3.first >> P3.second;

  cout << solve(P1, P2, P3) << '\n';

  return 0;
}

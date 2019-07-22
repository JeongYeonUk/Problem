#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 100003;
const int INF = 0x7FFFFFFF;

ll ccw(pll a, pll b, pll c)
{
  ll op = a.first * b.second
    + b.first * c.second
    + c.first * a.second;
  op -= (a.second * b.first
    + b.second * c.first
    + c.second * a.first);
  return op;
}

//int isInter(pair<pii, pii> x, pair<pii, pii> y)
//{
//  pii a = x.first;
//  pii b = x.second;
//  pii c = y.first;
//  pii d = y.second;
//  int ab = ccw(a, b, c) * ccw(a, b, d);
//  int cd = ccw(c, d, a) * ccw(c, d, b);
//  if (ab == 0 && cd == 0)
//  {
//    if (a > b) swap(a, b);
//    if (c > d) swap(c, d);
//    return c <= b && a <= d;
//  }
//  return ab <= 0 && cd <= 0;
//}

pll arr[MAX_N];
int N;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i].first >> arr[i].second;
  }

  pll start = arr[1];
  ll result = 0;
  for (int i = 2; i <= N - 1; ++i)
  {
    result += ccw(start, arr[i], arr[i + 1]);
  }

  if (result < 0)
    result *= -1;

  cout << result / 2 << '.' << (result % 2 == 0 ? 0 : 5) << '\n';

  return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

inline int MAX(int a, int b)
{
  return a > b ? a : b;
}

inline int MIN(int a, int b)
{
  return a > b ? b : a;
}

inline int GCD(int a, int b)
{
  return b == 0 ? a : GCD(b, a % b);
}

inline int CEIL(int a, int b)
{
  return (a + b - 1) / b;
}

int a[100001];
int d[100001];

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  d[1] = a[1];
  for (int i = 2; i <= n; ++i)
  {
    d[i] = a[i];
    d[i] = MAX(d[i], d[i - 1] + a[i]);
  }
  int ans = d[1];
  for (int i = 1; i <= n; ++i)
  {
    ans = MAX(ans, d[i]);
  }
  cout << ans << '\n';
  return 0;
}

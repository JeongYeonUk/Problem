#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 301;

inline int max(int a, int b)
{
  return a > b ? a : b;
}

int a[MAX_N];
int d[MAX_N];
int N;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> a[i];
  }
  d[1] = a[1];
  d[2] = a[1] + a[2];
  for (int i = 3; i <= N; ++i)
  {
    d[i] = d[i - 3] + a[i] + a[i - 1];
    d[i] = max(d[i], d[i - 2] + a[i]);
  }

  cout << d[N] << '\n';

  return 0;
}

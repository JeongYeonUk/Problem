#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

inline int min(int a, int b)
{
  return a > b ? b : a;
}

const int INF = 987654321;
const int MAX_N = 100001;
int d[MAX_N];
int N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    d[i] = i;
  }
  for (int i = 2; i <= N; ++i)
  {
    for (int j = 2; j * j <= i; ++j)
    {
      d[i] = min(d[i], d[i - j*j] + 1);
    }
  }
  cout << d[N] << '\n';
  return 0;
}

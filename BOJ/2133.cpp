#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 31;
int d[MAX_N];
int N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  d[0] = 1;
  for (int i = 2; i <= N; i += 2)
  {
    d[i] = d[i - 2] * 3;
    for (int j = i - 4; j >= 0; j -= 2)
    {
      d[i] += d[j] * 2;
    }
  }
  cout << d[N] << '\n';
  return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 100001;

inline int max(int a, int b)
{
  return a > b ? a : b;
}

int arr[MAX_N];
int d[MAX_N];
int N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i];
  }
  d[1] = arr[1];

  for (int i = 2; i <= N; ++i)
  {
    d[i] = arr[i];
    d[i] = max(d[i], d[i - 1] + arr[i]);
  }
  int ret = d[1];
  for (int i = 1; i <= N; ++i)
  {
    ret = max(ret, d[i]);
  }
  cout << ret << '\n';
  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  int sum = 0;
  for (int i = 0; i < N; ++i)
  {
    int a, b; cin >> a >> b;
    sum += b % a;
  }
  cout << sum << '\n';
  return 0;
}

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
  if (N % 10 != 0)
    cout << "-1\n";
  else
    cout << N / 300 << ' ' << N % 300 / 60 << ' ' << N % 60 / 10 << '\n';
  
  return 0;
}

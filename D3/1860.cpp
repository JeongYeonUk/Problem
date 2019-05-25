#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    vector<int> a;
    a.reserve(MAX);
    int N, M, K; cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
      int val; cin >> val;
      a.push_back(val);
    }
    sort(a.begin(), a.end());
    bool flag = false;
    for (int i = 0; i < a.size(); ++i)
    {
      if (a[i] / M * K < (i + 1))
        flag = true;
      if (flag)
        break;
    }
    cout << '#' << cases << ' ';
    cout << (flag ? "Impossible" : "Possible") << '\n';
  }

  return 0;
}

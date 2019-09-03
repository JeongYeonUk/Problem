#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321;

struct Data
{
  int s, e, x;
  bool operator<(const Data& rhs) const
  {
    if (e != rhs.e)
      return e < rhs.e;
    return s < rhs.s;
  }
};
int n, c, m;
vector<Data> v;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n >> c >> m;
  v.resize(m);
  for (int i = 0; i < m; ++i)
    cin >> v[i].s >> v[i].e >> v[i].x;
  sort(v.begin(), v.end());

  int ans = 0;
  vector<int> gogo(n + 1);
  for (int i = 0; i < m; ++i)
  {
    int maxi = 0;
    for (int j = v[i].s; j < v[i].e; ++j)
    {
      maxi = max(maxi, gogo[j]);
    }
    int left = min(v[i].x, c - maxi);
    ans += left;
    for (int j = v[i].s; j < v[i].e; ++j)
      gogo[j] += left;
  }
  cout << ans << '\n';
  return 0;
}

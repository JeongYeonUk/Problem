#pragma warning (disable : 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int camera[(1000001 << 1)];
vector<int> v;
vector<int> diff;
int n, k;
int main()
{
  int T; scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases)
  {
    scanf("%d %d", &n, &k);
    memset(camera, 0, sizeof(camera));
    v.clear();
    diff.clear();
    for (int i = 0; i < n; ++i)
    {
      int x; scanf("%d", &x);
      camera[x + 1000001] = 1;
    }
    for (int i = 0; i < (1000001 << 1); ++i)
    {
      if (camera[i])
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < (int)v.size(); ++i)
    {
      int delta = v[i] - v[i - 1];
      diff.push_back(delta);
    }
    sort(diff.begin(), diff.end());
    int size = diff.size();
    int ans = 0;
    for (int i = 0; i < size - (k - 1); ++i)
    {
      ans += diff[i];
    }
    printf("#%d %d\n", cases, ans);
  }

  return 0;
}

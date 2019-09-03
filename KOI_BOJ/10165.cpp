#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

const int INF = 987654321;

struct Data
{
  int s, e, x;
  bool operator <(const Data& rhs) const
  {
    if (s == rhs.s)
      return e > rhs.e;
    return s < rhs.s;
  }
};

bool cmp(const Data& a, const Data& b)
{
  return a.x < b.x;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<Data> v(m);

  int back = 0;
  for (int i = 0; i < m; ++i)
  {
    cin >> v[i].s >> v[i].e;
    v[i].x = i+1;
    if (v[i].s > v[i].e)
    {
      back = max(back, v[i].e);
      v[i].e += n;
    }
  }

  sort(v.begin(), v.end());

  deque<Data> dq;
  for (int i = 0; i < (int)v.size(); ++i)
  {
    if (dq.empty() || dq.back().e < v[i].e)
      dq.push_back(v[i]);
  }
  while (!dq.empty() && dq.front().e <= back)
    dq.pop_front();

  sort(dq.begin(), dq.end(), cmp);

  for (int i = 0; i < (int)dq.size(); ++i)
  {
    cout << dq[i].x << ' ';
  }
  cout << '\n';
  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7FFFFFFF;

vector<pii> vec;
vector<pair<pii, pii>> line;
int N, K, H, M;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K >> H >> M;
  for (int i = 0; i < N; ++i)
  {
    pii corner;
    cin >> corner.first >> corner.second;
    vec.push_back(corner);
  }

  int idx = 0;
  int cnt = N;
  while (cnt--)
  {
    int nidx = idx + 1;
    if (nidx == N)
      nidx = 0;
    pair<pii, pii> x = { vec[idx], vec[nidx] };
    line.push_back(x);
    idx++;
  }

  for (int i = 0; i < K; ++i)
  {
    pii hole;
    cin >> hole.first >> hole.second;
  }
  return 0;
}

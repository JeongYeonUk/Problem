#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

long long pSum[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int r, c, q;
  cin >> r >> c >> q;
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      int num; cin >> num;
      pSum[y + 1][x + 1] = pSum[y + 1][x] + pSum[y][x + 1]
        - pSum[y][x] + num;
    }
  }
  for (int i = 0; i < q; ++i) {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    long long sum = pSum[r2][c2] - pSum[r1 - 1][c2] - pSum[r2][c1 - 1]
      + pSum[r1 - 1][c1 - 1];
    int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
    cout << sum / cnt << endl;
  }
  return 0;
}

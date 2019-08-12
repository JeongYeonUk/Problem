#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 100001;

int N, M;
int arr[2* MAX_N];
int tree[2 * MAX_N];

void update(int i, int val)
{
  while (i <= N + M)
  {
    tree[i] += val;
    i += (i & -i);
  }
}

int sum(int i)
{
  int ret = 0;
  while (i > 0)
  {
    ret += tree[i];
    i -= (i & -i);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {
    cin >> N >> M;
    memset(tree, 0, sizeof(tree));
    memset(arr, 0, sizeof(arr));
    for (int i = M + 1; i <= M + N; ++i)
    {
      arr[i - M] = i;
      update(i, 1);
    }
    int a = M;
    for (int i = 1; i <= M; ++i)
    {

      int node; cin >> node;
      int ret = sum(arr[node] - 1);
      cout << ret << ' ';
      update(arr[node], -1);
      arr[node] = a--;
      update(arr[node], 1);
    }
    cout << '\n';
  }

  return 0;
}

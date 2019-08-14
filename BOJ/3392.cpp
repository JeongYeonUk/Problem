#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 10001;
const int MAX_Y = 30001;

struct Point
{
  int x, y1, y2, line;
};

bool cmp(Point& a, Point& b)
{
  return a.x < b.x;
}

int tree[MAX_Y * 4];
int cnt[MAX_Y * 4];
Point arr[MAX_N * 2];
int N;

void update(int node, int left, int right, int uleft, int uright, int val)
{
  if (uright < left || right < uleft)
    return;
  if (uleft <= left && right <= uright)
  {
    cnt[node] += val;
  }
  else
  {
    int mid = (left + right) >> 1;
    update(node * 2, left, mid, uleft, uright, val);
    update(node * 2 + 1, mid + 1, right, uleft, uright, val);
  }
  if (cnt[node])
  {
    tree[node] = right - left + 1;
  }
  else
  {
    if (left == right)
      tree[node] = 0;
    else
      tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    arr[i] = { x1,y1,y2 - 1,1 };
    arr[i + N] = { x2,y1,y2 - 1,-1 };
  }

  sort(arr, arr + N * 2, cmp);

  int last = 0;
  int ret = 0;
  for (int i = 0; i < N * 2; ++i)
  {
    if (i)
    {
      int dx = arr[i].x - last;
      ret += dx * tree[1];
    }
    update(1, 0, MAX_Y - 1, arr[i].y1, arr[i].y2, arr[i].line);
    last = arr[i].x;
  }

  cout << ret << '\n';

  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 0x7FFFFFFF;
const int MAX_N = 503;

vector<int> tall[MAX_N];
vector<int> small[MAX_N];
bool visit[MAX_N];
int result[MAX_N];
int ans;
int N, M;

void taller(int start)
{
  int size = (int)tall[start].size();
  if (!size)
    return;
  for (int i = 0; i < size; ++i)
  {
    if (!visit[tall[start][i]])
    {
      visit[tall[start][i]] = true;
      ans++;
      taller(tall[start][i]);
    }
  }
  return;
}

void smaller(int start)
{
  int size = (int)small[start].size();
  if (!size)
    return;
  for (int i = 0; i < size; ++i)
  {
    if (!visit[small[start][i]])
    {
      visit[small[start][i]] = true;
      ans++;
      smaller(small[start][i]);
    }
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;
  for (int i = 1; i <= M; ++i)
  {
    int a, b; cin >> a >> b;
    tall[a].push_back(b);
    small[b].push_back(a);
  }

  for (int i = 1; i <= N; ++i)
  {
    memset(visit, false, sizeof(visit));
    ans = 0;
    taller(i);
    result[i] = ans;
  }
  for (int i = 1; i <= N; ++i)
  {
    memset(visit, false, sizeof(visit));
    ans = 0;
    smaller(i);
    result[i] += ans;
  }

  int cnt = 0;
  for (int i = 1; i <= N; ++i)
  {
    if (result[i] + 1 == N)
      cnt++;
  }
  cout << cnt << '\n';

  return 0;
}

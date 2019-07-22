#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 103;
const int MAX_K = 1000000000;

int cache[MAX_N][MAX_N];
bool check;
string ans;
int N, M, K;

int getCount(int A, int Z)
{
  if (A == 0 || Z == 0)
    return 1;
  int& ret = cache[A][Z];
  if (ret > 0) return ret;
  return ret = min((getCount(A - 1, Z) + getCount(A, Z - 1))
    , MAX_K + 1);
}

void getWord(int A, int Z, int skip)
{
  if (A == 0)
  {
    for (int i = 0; i < Z; ++i)
    {
      ans += 'z';
    }
    return;
  }
  if (Z == 0)
  {
    for (int i = 0; i < A; ++i)
    {
      ans += 'a';
    }
    return;
  }
  int idx = getCount(A - 1, Z);

  if (skip < idx)
  {
    ans += 'a';
    getWord(A - 1, Z, skip);
  }
  else if (skip <= MAX_K)
  {
    ans += 'z';
    getWord(A, Z - 1, skip - idx);
  }
  else
    check = true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> K;
  if (K > getCount(N, M))
    check = true;
  else
    getWord(N, M, K - 1);

  if (check)
    cout << "-1\n";
  else
    cout << ans << '\n';
  return 0;
}

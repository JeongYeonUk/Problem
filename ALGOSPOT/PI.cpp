#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int INF = 987654321;
string N;
int cache[10001];

inline int MAX(int a, int b)
{
  return a > b ? a : b;
}

inline int MIN(int a, int b)
{
  return a > b ? b : a;
}

int classify(int a, int b)
{
  string M = N.substr(a, b - a + 1);

  if (M == string(M.size(), M[0])) return 1;

  bool progressive = true;
  for (int i = 0; i < M.size()-1; ++i)
  {
    if (M[i + 1] - M[i] != M[1] - M[0])
    {
      progressive = false;
      break;
    }
  }
  int sub = M[1] - M[0];
  sub = sub > 0 ? sub : -sub;
  if (progressive && sub == 1)
    return 2;

  bool alter = true;
  for (int i = 0; i < M.size(); ++i)
  {
    if (M[i] != M[i % 2])
    {
      alter = false;
      break;
    }
  }
  if (alter) return 4;
  if (progressive) return 5;
  return 10;
}

int solve(int begin)
{
  if (begin == N.size()) return 0;
  int& ret = cache[begin];
  if (ret != -1) return ret;
  ret = INF;
  for (int L = 3; L <= 5; ++L)
  {
    if (begin + L <= N.size())
    {
      ret = MIN(ret, solve(begin + L) + classify(begin, begin + L - 1));
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {    
    memset(cache, -1, sizeof(cache));
    cin >> N;
    cout << solve(0) << '\n';
  }

  return 0;
}

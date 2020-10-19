#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <stack>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(string s)
{
  int s_size = (int)s.size();
  stack<char> stk;
  for (int i = 0; i < s_size; ++i)
  {
    if (stk.empty() || (stk.top() != s[i]))
    {
      stk.push(s[i]);
    }
    else
    {
      stk.pop();
    }
  }

  return stk.empty() ? 1 : 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cout << solution("baabaa") << endl;

  return 0;
}

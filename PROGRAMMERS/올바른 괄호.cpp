#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool solution(string s)
{
  bool answer = true;
  stack<char> stk;
  for (int i = 0; i < s.length(); ++i)
  {
    if (stk.empty())
    {
      if (s[i] == ')')
        return false;
      else
        stk.push(s[i]);
    }
    else
    {
      if (s[i] == ')' && stk.top() == '(')
      {
        stk.pop();
      }
      else if (s[i] == '(')
      {
        stk.push(s[i]);
      }
    }
  }
  if (stk.empty())
    answer = true;
  else
    answer = false;
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution(")()(");

  return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string to_lower(const string &s)
{
  string ret = "";
  for (int i = 0; i < (int)s.size(); ++i)
  {
    if ('A' <= s[i] && s[i] <= 'Z')
    {
      ret += tolower(s[i]);
      continue;
    }
    ret += s[i];
  }
  return ret;
}

string solution(string s)
{
  s = to_lower(s);

  if ('a' <= s[0] && s[0] <= 'z')
  {
    s[0] = toupper(s[0]);
  }

  bool space = false;
  for (int i = 0; i < (int)s.size(); ++i)
  {
    if (s[i] == ' ')
    {
      space = true;
    }
    else if (space && ('a' <= s[i] && s[i] <= 'z'))
    {
      s[i] = toupper(s[i]);
      space = false;
    }
  }
  return s;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cout << solution("3people unFollowed me") << endl;

  return 0;
}

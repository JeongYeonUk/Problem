#pragma warning (disable:4996)
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct INFO
{
  int up, down;
};

map<string, INFO> m;

INFO cal(INFO info, char ch, int cnt)
{
  int leftUp = info.up, leftDown = info.down;
  int rightUp = 90, rightDown = (1 << cnt);
  int div = leftDown != 0 ? rightDown / leftDown : 0;
  if (ch == 'w')
  {
    if (leftDown == 0)
    {
      leftUp *= rightDown;
      leftUp += rightUp;
      while (true)
      {
        if (leftUp % 2 == 1)
          break;
        leftUp >>= 1;
        rightDown >>= 1;
      }
      leftDown = rightDown;
    }
    else
    {
      leftUp *= div; leftDown *= div;
      leftUp += rightUp;
      while (true)
      {
        if (leftUp % 2 == 1)
          break;
        leftUp >>= 1;
        leftDown >>= 1;
      }
    }
  }
  else
  {
    if (leftDown == 0)
    {
      leftUp *= rightDown;
      leftUp -= rightUp;
      while (true)
      {
        if (leftUp % 2 == 1)
          break;
        leftUp >>= 1;
        rightDown >>= 1;
      }
      leftDown = rightDown;
    }
    else
    {
      leftUp *= div; leftDown *= div;
      leftUp -= rightUp;
      while (true)
      {
        if (leftUp % 2 == 1)
          break;
        leftUp >>= 1;
        leftDown >>= 1;
      }
    }
  }
  return { leftUp, leftDown };
}

INFO solve(const string& s, char ch)
{
  int len = (int)s.length();
  int a = ch == 't' ? 5 : 6;
  int cnt = 0;
  for (int i = len - 1; i >= 0;)
  {
    cnt = 0;
    if (s[i] == 't')
    {
      if (i - 3 >= 0)
      {
        while (true)
        {
          if (s[i] == 'w')
            break;
          --i;
        }
        string some(s.begin() + i, s.end());
        if (m.find(some) == m.end())
        {
          string temp(s.begin() + i + 4, s.end());
          for (int j = 0; j < (int)temp.length();)
          {
            if (temp[j] == 'n')
            {
              j += 5;
              cnt++;
            }
            else if (temp[j] == 'w')
            {
              j += 4;
              cnt++;
            }
          }
          m[some] = cal(m[temp], 'w', cnt);
          i -= 1;
        }
        else
        {
          i -= 1;
        }
      }
    }
    else if (s[i] == 'h')
    {
      if (i - 4 >= 0)
      {
        while (true)
        {
          if (s[i] == 'n')
            break;
          --i;
        }
        string some(s.begin()+i, s.end());
        if (m.find(some) == m.end())
        {
          string temp(s.begin() + i + 5, s.end());
          for (int j = 0; j < (int)temp.length();)
          {
            if (temp[j] == 'n')
            {
              j += 5;
              cnt++;
            }
            else if (temp[j] == 'w')
            {
              j += 4;
              cnt++;
            }
          }
          m[some] = cal(m[temp], 'n', cnt);
          i -= 1;
        }
        else
        {
          i -= 1;
        }
      }
    }
  }
  return m[s];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  m["west"] = { 90,0 };
  m["north"] = { 0,0 };
  freopen("input.txt", "r", stdin);
  int T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    string s; cin >> s;
    if (m.find(s) != m.end())
    {
      if (m[s].down == 0 || m[s].down == 1)
      {
        cout << '#' << cases << ' ' << m[s].up << '\n';
      }
      else
      {
        cout << '#' << cases << ' ' << m[s].up << '/' << m[s].down << '\n';
      }
      continue;
    }
    char ch = s.back();
    INFO ans = solve(s, ch);
    if (ans.down == 0 || ans.down == 1)
      cout << '#' << cases << ' ' << ans.up << '\n';
    else
      cout << '#' << cases << ' ' << ans.up << '/' << ans.down << '\n';
  }

  return 0;
}

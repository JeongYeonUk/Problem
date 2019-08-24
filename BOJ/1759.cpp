#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int L, C;
vector<char> ch;

bool check(string& str)
{
  int size = (int)str.length();
  int mo = 0;
  int za = 0;
  for (int i = 0; i < size; ++i)
  {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
    {
      mo++;
    }
    else
      za++;
  }
  return za >= 2 && mo >= 1;
}

void solve(int depth, int s, int e, string str)
{
  if (depth == L)
  {
    if(check(str))
      cout << str << '\n';
    return;
  }
  for (int i = s; i <= e; ++i)
  {
    if(str == "")
      str += ch[i];
    else
    {
      if (str.back() < ch[i])
        str += ch[i];
    }
    solve(depth + 1, i + 1, e, str);
    str.pop_back();
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> L >> C;
  for (int i = 0; i < C; ++i)
  {
    char c; cin >> c;
    ch.push_back(c);
  }

  sort(ch.begin(), ch.end());

  solve(0,0,C-1, "");

  return 0;
}

#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int S[14];
int D[14];
int H[14];
int C[14];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);
  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    memset(S, 0, sizeof(S));
    memset(D, 0, sizeof(D));
    memset(H, 0, sizeof(H));
    memset(C, 0, sizeof(C));
    string str; cin >> str;
    int len = (int)str.length();
    for (int i = 0; i < len; i += 3)
    {
      if (str[i] == 'S')
      {
        int ten = str[i + 1] - '0';
        int one = str[i + 2] - '0';
        S[ten * 10 + one]++;
      }
      else if (str[i] == 'D')
      {
        int ten = str[i + 1] - '0';
        int one = str[i + 2] - '0';
        D[ten * 10 + one]++;
      }
      else if (str[i] == 'H')
      {
        int ten = str[i + 1] - '0';
        int one = str[i + 2] - '0';
        H[ten * 10 + one]++;
      }
      else
      {
        int ten = str[i + 1] - '0';
        int one = str[i + 2] - '0';
        C[ten * 10 + one]++;
      }
    }
    bool flag = true;
    int s, d, h, c;
    s = d = h = c = 0;
    for (int i = 1; i <= 13; ++i)
    {
      if (S[i] == 2 || D[i] == 2 || H[i] == 2 || C[i] == 2)
      {
        flag = false;
        break;
      }
      if (S[i] == 0)
        s++;
      if (D[i] == 0)
        d++;
      if (H[i] == 0)
        h++;
      if (C[i] == 0)
        c++;
    }
    cout << '#' << cases << ' ';
    if (flag)
      cout << s << ' ' << d << ' ' << h << ' ' << c << '\n';
    else
      cout << "ERROR" << '\n';
  }

  return 0;
}

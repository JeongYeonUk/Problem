#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int aChk[10];
int bChk[10];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);
  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    memset(aChk, 0, sizeof(aChk));
    memset(bChk, 0, sizeof(bChk));
    string a, b; cin >> a >> b;
    int aLen = (int)a.length();
    int bLen = (int)b.length();
    if (aLen != bLen)
    {
      cout << '#' << cases << ' ' << "DIFF" << '\n';
      continue;
    }
    for (int i = 0; i < aLen; ++i)
    {
      int temp = a[i] - 'A';
      switch (temp)
      {
      case 1:
        aChk[i] += 2;
        break;
      case 0:
      case 3:
      case 14:
      case 15:
      case 16:
      case 17:
        aChk[i] += 1;
        break;
      default:
        break;
      }
    }
    for (int i = 0; i < bLen; ++i)
    {
      int temp = b[i] - 'A';
      switch (temp)
      {
      case 1:
        bChk[i] += 2;
        break;
      case 0:
      case 3:
      case 14:
      case 15:
      case 16:
      case 17:
        bChk[i] += 1;
        break;
      default:
        break;
      }
    }
    bool flag = true;
    for (int i = 0; i < 10; ++i)
    {
      if (aChk[i] != bChk[i])
      {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << '#' << cases << ' ' << "SAME" << '\n';
    else
      cout << '#' << cases << ' ' << "DIFF" << '\n';
  }

  return 0;
}

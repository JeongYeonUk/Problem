#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
  while (true)
  {
    string s;
    getline(cin, s);
    if (s == "END")
      break;
    s = string(s.rbegin(), s.rend());
    cout << s << '\n';
  }

  return 0;
}

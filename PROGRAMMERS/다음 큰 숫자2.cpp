#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int getCount(int n)
{
  int cnt = 0;
  while (n)
  {
    if (n % 2 == 1)
      cnt++;
    n /= 2;
  }
  return cnt;
}

int solution(int n)
{
  int answer = 0;

  int cnt1 = getCount(n);
  int cnt2 = 0;
  while (true)
  {
    cnt2 = getCount(++n);
    if (cnt1 == cnt2)
    {
      answer = n;
      break;
    }
  }

  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution(78) << endl;;

  return 0;
}

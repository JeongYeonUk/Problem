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
#define CUR_POS first
#define BATTERY second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(int n)
{
  int answer = 0;

  while (n != 0)
  {
    if (n % 2 == 0)
    {
      n >>= 1;
    }
    else
    {
      n -= 1;
      answer++;
    }
  }

  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cout << solution(1) << endl;
  cout << solution(2) << endl;
  cout << solution(5000) << endl;
  cout << solution(5) << endl;
  cout << solution(6) << endl;

  return 0;
}

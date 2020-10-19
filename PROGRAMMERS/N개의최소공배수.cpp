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

int gcd(int x, int y)
{
  if (x < y)
    swap(x, y);

  int rest;
  while (y != 0)
  {
    rest = x % y;
    x = y;
    y = rest;
  }
  return x;
}

int lcm(int x, int y)
{
  return x * y / gcd(x, y);
}

int solution(vector<int> arr)
{
  sort(arr.begin(), arr.end());

  int answer = lcm(arr[0], arr[1]);
  for (int i = 2; i < (int)arr.size(); ++i)
  {
    answer = lcm(answer, arr[i]);
  }
  return answer;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  return 0;
}

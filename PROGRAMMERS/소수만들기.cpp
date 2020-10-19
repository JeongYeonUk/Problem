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

bool is_prime(int n)
{
  if (n == 1 || n == 0)
    return false;
  for (int i = 2; i < (n >> 1); ++i)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

int solution(vector<int> nums)
{
  int nums_size = (int)nums.size();
  int sum = 0;
  int answer = 0;
  for (int i = 0; i < nums_size - 2; ++i)
  {
    for (int j = i + 1; j < nums_size - 1; ++j)
    {
      for (int k = j + 1; k < nums_size; ++k)
      {
        sum = nums[i] + nums[j] + nums[k];
        if (is_prime(sum))
          answer++;
      }
    }
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

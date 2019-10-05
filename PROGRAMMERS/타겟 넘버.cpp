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

void dfs(int& answer, const vector<int>& numbers, int target, int sum, int idx)
{
  if (idx >= (int)numbers.size())
  {
    if (sum == target)
      answer++;
    return;
  }
  dfs(answer, numbers, target, sum + numbers[idx], idx + 1);
  dfs(answer, numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target)
{
  int answer = 0;
  dfs(answer, numbers, target, 0, 0);
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution({1,1,1,1,1},3) << endl;

  return 0;
}

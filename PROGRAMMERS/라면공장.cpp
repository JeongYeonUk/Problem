#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
  int answer = 0;
  int size = (int)dates.size();
  int idx = 0;
  priority_queue<int, vector<int>, less<int>> pq;
  for (int i = 0; i < k; ++i)
  {
    if (i == dates[idx])
    {
      pq.push(supplies[idx]);
      if (idx != size - 1)
        idx++;
    }
    if (stock == 0)
    {
      stock += pq.top();
      pq.pop();
      answer++;
    }
    stock -= 1;
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution(4, {1,2,3,4}, {10,40,30,20},100) << endl;

  return 0;
}

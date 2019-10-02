#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  int min_first = 0;
  int min_second = 0;
  priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
  while (pq.top() < K)
  {
    if (pq.size() < 2)
    {
      answer = -1;
      break;
    }
    min_first = pq.top(); pq.pop();
    min_second = pq.top(); pq.pop();

    pq.push(min_first + (min_second << 1));
    answer++;
  }

  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution({ 1,2,3,9,10,12 },7);

  return 0;
}

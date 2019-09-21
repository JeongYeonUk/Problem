#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> solution(vector<int> prices) {
  vector<int> answer(prices.size());
  stack<int> s;
  int size = prices.size();
  for (int i = 0; i < size; i++) {
    while (!s.empty() && prices[s.top()] > prices[i]) {
      answer[s.top()] = i - s.top();
      s.pop();
    }
    s.push(i);
  }

  while (!s.empty()) {
    answer[s.top()] = size - s.top() - 1;
    s.pop();
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  vector<int> ret = solution({1,2,3,2,3});
  for (auto elem : ret) {
    cout << elem << ' ';
  }

  return 0;
}

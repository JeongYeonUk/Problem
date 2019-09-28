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

vector<int> solution(vector<int> heights) {
  vector<int> answer;
  int size = (int)heights.size();
  bool flag;
  for (int i = size-1; i >= 0; --i) {
    flag = true;
    for (int j = i - 1; j >= 0; --j) {
      if (heights[i] < heights[j]) {
        answer.push_back(j + 1);
        flag = false;
        break;
      }
    }
    if (flag) {
      answer.push_back(0);
    }
  }
  reverse(answer.begin(), answer.end());
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  vector<int> ret = solution({ 3,9,9,3,5,7,2 });
  for (auto elem : ret) {
    cout << elem << ' ';
  }
  return 0;
}

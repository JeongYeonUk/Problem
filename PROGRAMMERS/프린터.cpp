#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct INFO {
  int prior;
  int pos;
};

int solution(vector<int> priorities, int location) {
  deque<INFO> dq;
  for (int i = 0; i < (int)priorities.size(); ++i) {
    dq.push_back({ priorities[i], i });
  }
  int answer = 1;
  while (!dq.empty()) {
    INFO cur = dq.front();
    dq.pop_front();
    bool flag = true;
    for (int i = 0; i < (int)dq.size(); ++i) {
      if (cur.prior < dq[i].prior) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      dq.push_back(cur);
    }
    else {
      if (location == cur.pos) {
        break;
      }
      else {
        answer++;
      }
    }
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution({ 1,1,9,1,1,1 },0) << endl;

  return 0;
}

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(string arrangement) {
  int answer = 0;
  stack<int> s;
  for (int i = 0; i < (int)arrangement.length(); ++i) {
    if (s.empty()) {
      s.push(i);
    }
    else if (arrangement[i] == '(') {
      s.push(i);
    }
    else if (arrangement[i] == ')') {
      if (s.top() + 1 == i) {
        s.pop();
        if (!s.empty()) {
          answer += (int)s.size();
        }
      }
      else {
        answer += 1;
        s.pop();
      }
    }
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution("()(((()())(())()))(())") << endl;

  return 0;
}

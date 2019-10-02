#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;

int solution(string name) {
  int answer = 0;
  int len = name.length();

  int tmp = 0, turn = len - 1;

  for (int i = 0; i < len; ++i)
  {
    int start = name[i] - 'A';
    int end = 'Z' - name[i] + 1;

    if (start > end)
      tmp += end;
    else
      tmp += start;

    int next = i + 1;
    while (next < len && name[next] == 'A')
      next++;

    turn = min(turn, i + len - next + min(i, len - next));
  }
  tmp += turn;
  answer = tmp;

  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution("AABAAAAAAAB") << endl;

  return 0;
}

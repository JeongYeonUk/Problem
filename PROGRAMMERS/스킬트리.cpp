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

int solution(string skill, vector<string> skill_trees) {
  int word[26] = { 0, };
  for (int i = 0; i < (int)skill.length(); ++i) {
    word[skill[i] - 'A'] = 1;
  }
  int answer = 0;

  int skill_idx;
  int trees_idx;
  bool flag;
  for (int i = 0; i < (int)skill_trees.size(); ++i) {
    skill_idx = 0;
    trees_idx = 0;
    flag = true;
    while (true) {
      if (skill_idx >= (int)skill.length()) {
        break;
      }
      if (trees_idx >= skill_trees[i].length()) {
        break;
      }
      if (skill[skill_idx] != skill_trees[i][trees_idx]) {
        if (word[skill_trees[i][trees_idx] - 'A']) {
          flag = false;
          break;
        }
        else {
          trees_idx++;
        }
      }
      else {
        skill_idx++;
        trees_idx++;
      }
    }
    if (flag) answer++;
  }

  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution("CBD", {"BACDE","CBADF","AECB","BDA"}) << endl;

  return 0;
}

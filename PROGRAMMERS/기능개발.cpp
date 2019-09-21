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

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  for (int i = 0; i < (int)progresses.size(); ++i) {
    progresses[i] = 100 - progresses[i];
  }
  for (int i = 0; i < (int)progresses.size(); ++i) {
    int divide = progresses[i] / speeds[i];
    int remind = (progresses[i] % speeds[i] != 0 ? 1 : 0);
    progresses[i] = divide + remind;
  }
  int tmp = progresses[0];
  int ans = 1;
  for (int i = 1; i < (int)progresses.size(); ++i) {
    if (tmp >= progresses[i]) {
      ans++;
    }
    else {
      answer.push_back(ans);
      tmp = progresses[i];
      ans = 1;
    }
  }
  answer.push_back(ans);
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);


  vector<int> ret = solution({ 93,30,55 }, { 1,30,5 });
  for (auto elem : ret) {
    cout << elem << ' ';
  }
  return 0;
}

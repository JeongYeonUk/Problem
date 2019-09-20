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

int solution(int n, vector<int> lost, vector<int> reserve)
{
  vector<int> answer(n,1);
  for (int i = 0; i < (int)lost.size(); ++i) {
    answer[lost[i]-1]--;
  }
  for (int i = 0; i < (int)reserve.size(); ++i) {
    answer[reserve[i]-1]++;
  }
  for (int i = 0; i < (int)answer.size(); ++i) {
    if (!i) {
      if (answer[i] == 0) {
        if (answer[i + 1] == 2) {
          answer[i] += 1;
          answer[i + 1] -= 1;
        }
      }
    }
    else if (i == (int)answer.size() - 1) {
      if (answer[i] == 0) {
        if (answer[i - 1] == 2) {
          answer[i] += 1;
          answer[i - 1] -= 1;
        }
      }
    }
    else {
      if (answer[i] == 0) {
        if (answer[i - 1] == 2) {
          answer[i - 1] -= 1;
          answer[i] += 1;
        }
        else if (answer[i + 1] == 2) {
          answer[i + 1] -= 1;
          answer[i] += 1;
        }
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < (int)answer.size(); ++i) {
    if (answer[i]) {
      ret++;
    }
  }  
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  int n = 5;
  vector<int> lost = { 1,3 };
  vector<int> reserve = { 2,3,4 };

  int ret = solution(n,lost,reserve);
  cout << ret << endl;
  return 0;
}

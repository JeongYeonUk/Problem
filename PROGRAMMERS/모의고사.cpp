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

int one[] = { 1,2,3,4,5 };
int two[] = { 2,1,2,3,2,4,2,5 };
int three[] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers)
{
  vector<int> answer;

  int one_size = sizeof(one) / sizeof(int);
  int two_size = sizeof(two) / sizeof(int);
  int three_size = sizeof(three) / sizeof(int);

  int one_score = 0;
  int two_score = 0;
  int three_score = 0;

  int answers_idx = 0;
  int idx = 0;
  while (true) {
    if (answers_idx == (int)answers.size()) {
      break;
    }      
    if (idx == one_size) {
      idx = 0;
    }
    if (answers[answers_idx] == one[idx]) {
      one_score++;
    }
    answers_idx++;
    idx++;
  }
  answers_idx = 0;
  idx = 0;
  while (true) {
    if (answers_idx == (int)answers.size()) {
      break;
    }
    if (idx == two_size) {
      idx = 0;
    }
    if (answers[answers_idx] == two[idx]) {
      two_score++;
    }
    answers_idx++;
    idx++;
  }
  answers_idx = 0;
  idx = 0;
  while (true) {
    if (answers_idx == (int)answers.size()) {
      break;
    }
    if (idx == three_size) {
      idx = 0;
    }
    if (answers[answers_idx] == three[idx]) {
      three_score++;
    }
    answers_idx++;
    idx++;
  }

  int maxi = max({ one_score, two_score, three_score });
  if (maxi == one_score) {
    answer.push_back(1);
  }
  if (maxi == two_score) {
    answer.push_back(2);
  }
  if (maxi == three_score) {
    answer.push_back(3);
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  vector<int> answers = { 1,3,2,4,2 };
  vector<int> ret = solution(answers);

  for (auto elem : ret) {
    cout << elem << ' ';
  }

  return 0;
}

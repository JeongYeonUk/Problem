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

bool cmp(const string& a, const string& b) {
  return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> v;
  for (auto elem : numbers) {
    v.push_back(to_string(elem));
  }
  sort(v.begin(), v.end(), cmp);
  for (auto str : v) {
    answer += str;
  }
  if (answer[0] == '0') {
    return "0";
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution({ 3,30,34,5,9 }) << endl;

  return 0;
}

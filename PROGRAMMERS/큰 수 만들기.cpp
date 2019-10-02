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

string solution(string number, int k) {
  string answer = "";
  int need = number.length() - k;
  int maxi = 0;
  int idx = 0;
  vector<int> ret;
  for (int i = need; i > 0; --i)
  {
    maxi = 0;
    idx = 0;
    for (int j = 0; j < number.length() - i + 1; ++j)
    {
      if (maxi < number[j])
      {
        maxi = number[j];
        idx = j;
      }
    }
    number.replace(0, idx + 1, " ");
    ret.push_back(maxi);
  }
  for (int i = 0; i < (int)ret.size(); ++i)
  {
    answer += ret[i];
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution("1924", 2) << endl;

  return 0;
}

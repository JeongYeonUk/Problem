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
  answer = number.substr(k);
  for (int i = k - 1; i >= 0; i--) {
    int j = 0;
    do {
      if (number[i] >= answer[j]) {
        char temp = answer[j];
        answer[j] = number[i];
        number[i] = temp;
        j++;
      }
      else {
        break;
      }
    } while (1);
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

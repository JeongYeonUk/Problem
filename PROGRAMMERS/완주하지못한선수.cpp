#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  sort(participant.begin(), participant.end());
  sort(completion.begin(), completion.end());

  for (int i = 0; i < (int)completion.size(); ++i) {
    if (participant[i] != completion[i]) {
      return participant[i];
    }
  }
  return participant[participant.size() - 1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  vector<string> participant = { "mislav","stanko","mislav","ana" };
  vector<string> completion = { "stanko","mislav","ana" };

  string answer = solution(participant, completion);

  cout << answer << endl;

  return 0;
}

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

int split(vector<int> array, vector<int> commands) {
  vector<int> tmp;
  for (int i = commands[0]-1; i <= commands[1]-1; ++i) {
    tmp.push_back(array[i]);
  }
  sort(tmp.begin(), tmp.end());
  return tmp[commands[2]-1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;

  for (auto elem : commands) {
    answer.push_back(split(array, elem));
  }

  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  vector<int> array = { 1,5,2,6,3,7,4 };
  vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };

  vector<int> ret = solution(array, commands);

  for (auto elem : ret) {
    cout << elem << ' ';
  }

  return 0;
}

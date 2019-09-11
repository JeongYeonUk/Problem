#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int N;
char input[10002];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> input;
  int bonus = 0, ret = 0;

  for (int idx = 0; input[idx] != NULL; ++idx) {
    if (input[idx] == 'O') {
      ret += idx + 1;
      ret += bonus;
      bonus++;
    }
    else if (input[idx] == 'X') {
      bonus = 0;
    }
  }

  cout << ret << endl;

  return 0;
}

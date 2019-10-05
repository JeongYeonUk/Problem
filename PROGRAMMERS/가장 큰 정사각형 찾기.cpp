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

int solution(vector<vector<int>> board)
{
  int answer = 0;
  int maxi = 0;
  int leny = board.size();
  int lenx = board[0].size();

  if (leny < 2 || lenx < 2)
  {
    for (int y = 0; y < leny; ++y)
    {
      for (int x = 0; x < lenx; ++x)
      {
        if (board[y][x] == 1)
          maxi = 1;
      }
    }
  }
  else
  {
    for (int y = 1; y < (int)board.size(); ++y)
    {
      for (int x = 1; x < (int)board[y].size(); ++x)
      {
        if (board[y][x] != 1)
          continue;
        board[y][x] = min({ board[y - 1][x - 1],board[y - 1][x], board[y][x - 1] }) + 1;
        maxi = max(board[y][x], maxi);
      }
    }
  }
  answer = maxi * maxi;
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution({ {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} }) << endl;

  return 0;
}

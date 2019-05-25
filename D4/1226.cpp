#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int map[16][16];
int check[16][16];
bool flag;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
void init(int index, string& str)
{
  for (int i = 0; i < (int)str.length(); ++i)
  {
    map[index][i] = (str[i] - '0');
  }
}
void solve(int y, int x)
{
  if (check[y][x]) return;
  check[y][x] = 1;
  for (int i = 0; i < 4; ++i)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (map[ny][nx] != 1)
    {
      if (map[ny][nx] == 3)
      {
        flag = true;
        return;
      }
      solve(ny, nx);
    }
  }
  check[y][x] = 0;
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);
  for (int cases = 1; cases <= 10; ++cases)
  {
    memset(map, 0, sizeof(map));
    memset(check, 0, sizeof(check));
    flag = false;
    int T; cin >> T;
    for (int i = 0; i < 16; ++i)
    {
      string str;
      cin >> str;
      init(i, str);
    }
    solve(1, 1);
    cout << '#' << cases << ' ' << (flag == true ? 1 : 0) << '\n';
  }

  return 0;
}

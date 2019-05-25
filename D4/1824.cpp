#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string arr[20];
int check[20][20];
int mem;
bool flag;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

void solve(int y, int x, int dir, int count)
{
  if (flag)
    return;
  char c = arr[y][x];
  if (0 <= (c - '0') && (c - '0') < 10)
  {
    mem = (c - '0');
    if (!check[y][x])
      check[y][x] = mem;
    if (x + dx[0] < 20)
      solve(y + dy[0], x + dx[0], 0, count + 1);
    else
      solve(y + dy[0], 0, 0, count + 1);
  }
  else if (c == '>')
  {
    if (check[y][x] == mem && count != 0)
    {
      flag = false;
      return;
    }
    if (!check[y][x])
      check[y][x] = mem;
    if (x + dx[0] < 20)
      solve(y + dy[0], x + dx[0], 0, count + 1);
    else
      solve(y + dy[0], 0, 0, count + 1);
  }
  else if (c == 'v')
  {
    if (check[y][x] == mem && count != 0)
    {
      flag = false;
      return;
    }
    if (!check[y][x])
      check[y][x] = mem;
    if (y + dy[1] < 20)
      solve(y + dy[1], x + dx[1], 1, count + 1);
    else
      solve(0, x + dx[1], 1, count + 1);
  }
  else if (c == '<')
  {
    if (check[y][x] == mem && count != 0)
    {
      flag = false;
      return;
    }
    if (!check[y][x])
      check[y][x] = mem;
    if (x + dx[2] < 0)
      solve(y + dy[2], 19, 2, count + 1);
    else
      solve(y + dy[2], x + dx[2], 2, count + 1);
  }
  else if (c == '^')
  {
    if (check[y][x] == mem && count != 0)
    {
      flag = false;
      return;
    }
    if (!check[y][x])
      check[y][x] = mem;
    if (y + dy[3] < 0)
      solve(19, x + dx[3], 3, count + 1);
    else
      solve(y + dy[3], x + dx[3], 3, count + 1);
  }
  else if (c == '-')
  {
    mem--;
    if (mem < 0)
      mem = 15;
    if (0 <= (y + dy[dir]) && (y + dy[dir]) < 20 && 0 <= (x + dx[dir]) && (x + dx[dir]) < 20)
      solve(y + dy[dir], x + dx[dir], dir, count + 1);
    else if (y + dy[dir] < 0)
      solve(19, x + dx[dir], dir, count + 1);
    else if (y + dy[dir] > 19)
      solve(0, x + dx[dir], dir, count + 1);
    else if (x + dx[dir] < 0)
      solve(y + dy[dir], 19, dir, count + 1);
    else if (x + dx[dir] > 19)
      solve(y + dy[dir], 0, dir, count + 1);
  }
  else if (c == '+')
  {
    mem++;
    if (mem > 15)
      mem = 0;
    if (0 <= (y + dy[dir]) && (y + dy[dir]) < 20 && 0 <= (x + dx[dir]) && (x + dx[dir]) < 20)
      solve(y + dy[dir], x + dx[dir], dir, count + 1);
    else if (y + dy[dir] < 0)
      solve(19, x + dx[dir], dir, count + 1);
    else if (y + dy[dir] > 19)
      solve(0, x + dx[dir], dir, count + 1);
    else if (x + dx[dir] < 0)
      solve(y + dy[dir], 19, dir, count + 1);
    else if (x + dx[dir] > 19)
      solve(y + dy[dir], 0, dir, count + 1);
  }
  else if (c == '_')
  {
    if (check[y][x] == mem && count != 0)
    {
      flag = false;
      return;
    }
    if (!check[y][x])
      check[y][x] = mem;
    if (mem == 0)
    {
      if (x + dx[0] < 20)
        solve(y + dy[0], x + dx[0], 0, count + 1);
      else
        solve(y + dy[0], 0, 0, count + 1);
    }
    else
    {
      if (x + dx[2] >= 0)
        solve(y + dy[2], x + dx[2], 2, count + 1);
      else
        solve(y + dy[2], 19, 2, count + 1);
    }
  }
  else if (c == '|')
  {
    if (check[y][x] == mem && count != 0)
    {
      flag = false;
      return;
    }
    if (!check[y][x])
      check[y][x] = mem;
    if (mem == 0)
    {
      if (y + dy[1] < 20)
        solve(y + dy[1], x + dx[1], 1, count + 1);
      else
        solve(0, x + dx[1], 1, count + 1);
    }
    else
    {
      if (y + dy[3] >= 0)
        solve(y + dy[3], x + dx[3], 3, count + 1);
      else
        solve(19, x + dx[3], 3, count + 1);
    }
  }
  else if (c == '?')
  {
    if (check[y][x] == mem && count != 0)
    {
      flag = false;
      return;
    }
    if (!check[y][x])
      check[y][x] = mem;
    if (x + dx[0] < 20)
      solve(y + dy[0], x + dx[0], 0, count + 1);
    else
      solve(y + dy[0], 0, 0, count + 1);

    if (y + dy[1] < 20)
      solve(y + dy[1], x + dx[1], 1, count + 1);
    else
      solve(0, x + dx[1], 1, count + 1);

    if (x + dx[2] < 0)
      solve(y + dy[2], 19, 2, count + 1);
    else
      solve(y + dy[2], x + dx[2], 2, count + 1);

    if (y + dy[3] < 0)
      solve(19, x + dx[3], 3, count + 1);
    else
      solve(y + dy[3], x + dx[3], 3, count + 1);
  }
  else if (c == '.')
  {
    if (0 <= (y + dy[dir]) && (y + dy[dir]) < 20 && 0 <= (x + dx[dir]) && (x + dx[dir]) < 20)
      solve(y + dy[dir], x + dx[dir], dir, count + 1);
    else if (y + dy[dir] < 0)
      solve(19, x + dx[dir], dir, count + 1);
    else if (y + dy[dir] > 19)
      solve(0, x + dx[dir], dir, count + 1);
    else if (x + dx[dir] < 0)
      solve(y + dy[dir], 19, dir, count + 1);
    else if (x + dx[dir] > 19)
      solve(y + dy[dir], 0, dir, count + 1);
  }
  else
  {
    flag = true;
    return;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);
  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    flag = false;
    memset(check, 0, sizeof(check));
    mem = 0;
    int R, C; cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
      cin >> arr[i];
    }
    solve(0, 0, 0, 0);
    cout << '#' << cases << ' ';
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }

  return 0;
}

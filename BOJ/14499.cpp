#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,-1,1 };

int n, m, sx, sy, k;
int map[20][20];
int dice[6];

void move_dice(int dir)
{
  int ndice[6] = { 0, };
  switch (dir)
  {
  case 0: // east
    ndice[0] = dice[0];
    ndice[1] = dice[4];
    ndice[2] = dice[2];
    ndice[3] = dice[5];
    ndice[4] = dice[3];
    ndice[5] = dice[1];
    break;
  case 1: // west
    ndice[0] = dice[0];
    ndice[1] = dice[5];
    ndice[2] = dice[2];
    ndice[3] = dice[4];
    ndice[4] = dice[1];
    ndice[5] = dice[3];
    break;
  case 2: // north
    ndice[0] = dice[1];
    ndice[1] = dice[2];
    ndice[2] = dice[3];
    ndice[3] = dice[0];
    ndice[4] = dice[4];
    ndice[5] = dice[5];
    break;
  case 3: // south    
    ndice[0] = dice[3];
    ndice[1] = dice[0];
    ndice[2] = dice[1];
    ndice[3] = dice[2];
    ndice[4] = dice[4];
    ndice[5] = dice[5];
    break;
  default:
    break;
  }

  for (int i = 0; i < 6; ++i)
    dice[i] = ndice[i];
}

int main()
{
  cin >> n >> m >> sy >> sx >> k;
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < m; ++x)
      cin >> map[y][x];
  }

  int dir;
  for (int i = 0; i < k; ++i)
  {
    cin >> dir;
    dir -= 1;
    int nx = sx + dx[dir];
    int ny = sy + dy[dir];
    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
      continue;

    move_dice(dir);

    if (map[ny][nx] == 0)
    {
      map[ny][nx] = dice[3];
    }
    else
    {
      dice[3] = map[ny][nx];
      map[ny][nx] = 0;
    }
    sy = ny;
    sx = nx;
    cout << dice[1] << endl;
  }

  return 0;
}

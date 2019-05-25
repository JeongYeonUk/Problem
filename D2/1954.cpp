#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10;

enum class direct
{
  up = 1,
  down = 2,
  left = 3,
  right = 4
};

int map[MAX][MAX];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    memset(map, 0, sizeof(map));
    int N; cin >> N;

    int number = 1;
    int x = 0, y = 0;
    int temp = static_cast<int>(direct::right);
    while (number != ((N * N) + 1))
    {
      switch (temp)
      {
      case 1:
      {
        map[y][x] = number++;
        if ((y - 1) > -1 && !map[y - 1][x])
        {
          y--;
        }
        else
        {
          temp = static_cast<int>(direct::right);
          x++;
        }
      }
      break;
      case 2:
      {
        map[y][x] = number++;
        if ((y + 1) < N && !map[y + 1][x])
        {
          y++;
        }
        else
        {
          temp = static_cast<int>(direct::left);
          x--;
        }
      }
      break;
      case 3:
      {
        map[y][x] = number++;
        if ((x - 1) > -1 && !map[y][x - 1])
        {
          x--;
        }
        else
        {
          temp = static_cast<int>(direct::up);
          y--;
        }
      }
      break;
      case 4:
      {
        map[y][x] = number++;
        if ((x + 1) < N && !map[y][x + 1])
        {
          x++;
        }
        else
        {
          temp = static_cast<int>(direct::down);
          y++;
        }
      }
      break;
      default:
        break;
      }
    }

    cout << '#' << cases << '\n';
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        cout << map[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}

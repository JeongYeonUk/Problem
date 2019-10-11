#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

const char block[19][4][5] = {
  {
    "1111",
    "0000",
    "0000",
    "0000",
  },
  {
    "1000",
    "1000",
    "1000",
    "1000",
  },
  {
    "1100",
    "1100",
    "0000",
    "0000",
  },
  {
    "1000",
    "1000",
    "1100",
    "0000",
  },
  {
    "1110",
    "1000",
    "0000",
    "0000",
  },
  {
    "1100",
    "0100",
    "0100",
    "0000",
  },
  {
    "0010",
    "1110",
    "0000",
    "0000",
  },
  {
    "0100",
    "0100",
    "1100",
    "0000",
  },
  {
    "1000",
    "1110",
    "0000",
    "0000",
  },
  {
    "1100",
    "1000",
    "1000",
    "0000",
  },
  {
    "1110",
    "0010",
    "0000",
    "0000",
  },
  {
    "0110",
    "1100",
    "0000",
    "0000",
  },
  {
    "1000",
    "1100",
    "0100",
    "0000",
  },
  {
    "1100",
    "0110",
    "0000",
    "0000",
  },
  {
    "0100",
    "1100",
    "1000",
    "0000",
  },
  {
    "1110",
    "0100",
    "0000",
    "0000",
  },
  {
    "1000",
    "1100",
    "1000",
    "0000",
  },
  {
    "0100",
    "1110",
    "0000",
    "0000",
  },
  {
    "0100",
    "1100",
    "0100",
    "0000",
  }
};

int N, M;
int map[503][503];

int get_count(int sy, int sx, int k)
{
  int ret = 0;

  for (int y = 0; y < 4; ++y)
  {
    for (int x = 0; x < 4; ++x)
    {
      ret += (block[k][y][x] - '0') * map[sy + y][sx + x];
    }
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> N >> M;
  for (int y = 0; y < N; ++y)
  {
    for (int x = 0; x < M; ++x)
    {
      cin >> map[y][x];
    }
  }
  for (int y = N; y < N + 3; ++y)
  {
    for (int x = 0; x < M + 3; ++x)
    {
      map[y][x] = -10000;
    }
  }
  for (int y = 0; y < N + 3; ++y)
  {
    for (int x = M; x < M + 3; ++x)
    {
      map[y][x] = -10000;
    }
  }

  int ret = 0;
  for (int y = 0; y < N; ++y)
  {
    for (int x = 0; x < M; ++x)
    {
      for (int k = 0; k < 19; ++k)
      {
        int candi = get_count(y, x, k);
        if (ret < candi)
          ret = candi;
      }
    }
  }
  cout << ret << endl;

  return 0;
}

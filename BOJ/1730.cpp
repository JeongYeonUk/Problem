#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

char wood[100][101];
char input[1001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  cin >> input;
  int idx = 0;
  for (; input[idx] != NULL; ++idx);
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      wood[y][x] = '.';
    }
  }
  int sy = 0, sx = 0;
  for (int i = 0; i < idx; ++i) {
    switch (input[i])
    {
    case 'U':
      if (sy - 1 >= 0) {
        if (wood[sy][sx] == '-')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '|';
        sy--;
        if (wood[sy][sx] == '-')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '|';
      }
      break;
    case 'D':
      if (sy + 1 < N) {
        if (wood[sy][sx] == '-')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '|';
        sy++;
        if (wood[sy][sx] == '-')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '|';
      }
      break;
    case 'R':
      if (sx + 1 < N) {
        if (wood[sy][sx] == '|')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '-';
        sx++;
        if (wood[sy][sx] == '|')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '-';
      }
      break;
    case 'L':
      if (sx - 1 >= 0) {
        if (wood[sy][sx] == '|')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '-';
        sx--;
        if (wood[sy][sx] == '|')
          wood[sy][sx] = '+';
        else if (wood[sy][sx] == '.')
          wood[sy][sx] = '-';
      }
      break;
    default:
      break;
    }
  }

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      cout << wood[y][x];
    }
    cout << endl;
  }

  return 0;
}

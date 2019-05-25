#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[100][100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);

  for (int cases = 1; cases <= 10; ++cases)
  {
    int N; cin >> N;
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        cin >> map[i][j];
      }
    }
    int count = 0;
    int index = 0;
    for (int i = 0; i < N; ++i)
    {
      while (index != 100)
      {
        if (map[index][i] == 1)
        {
          for (int j = index; j < N; ++j)
          {
            if (map[j][i] == 2)
            {
              count++;
              index = j;
              break;
            }
          }
        }
        index++;
      }
      index = 0;
    }
    cout << '#' << cases << ' ' << count << '\n';
  }



  return 0;
}

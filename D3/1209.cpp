#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int map[MAX][MAX];

int colSum()
{
  int max = 0;
  for (int i = 0; i < MAX; ++i)
  {
    int sum = 0;
    for (int j = 0; j < MAX; ++j)
    {
      sum += map[j][i];
    }
    if (max < sum)
      max = sum;
  }
  return max;
}
int rowSum()
{
  int max = 0;
  for (int i = 0; i < MAX; ++i)
  {
    int sum = 0;
    for (int j = 0; j < MAX; ++j)
    {
      sum += map[i][j];
    }
    if (max < sum)
      max = sum;
  }
  return max;
}
int crossSum()
{
  int sum = 0;
  int i = 0, j = 0;
  while (true)
  {
    if (i == MAX && j == MAX)
      break;
    sum += map[i][j];
    i++; j++;
  }
  i = 0; j = MAX - 1;
  int sum2 = 0;
  while (true)
  {
    if (i == MAX && j < 0)
      break;
    sum2 += map[i][j];
    i++; j--;
  }
  return (sum > sum2 ? sum : sum2);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int cases = 1; cases <= 10; ++cases)
  {
    int N; cin >> N;
    for (int i = 0; i < MAX; ++i)
    {
      for (int j = 0; j < MAX; ++j)
      {
        cin >> map[i][j];
      }
    }
    int col = colSum();
    int row = rowSum();
    int cross = crossSum();
    int ans = max(col, max(row, cross));
    cout << '#' << N << ' ' << ans << '\n';
  }

  return 0;
}

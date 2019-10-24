#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };
struct INFO
{
  int y, x;
};

int map[20][20];
int label[20][20];
int n, ret;
int val[6];

int findArea(INFO start, INFO end, int number)
{
  int sum = 0;
  if (number == 1)
  {
    for (int y = start.y; y <= end.y; ++y)
    {
      for (int x = start.x; x <= end.x; ++x)
      {
        if (label[y][x] == 5)
          continue;
        if (label[y][x] == 0)
        {
          sum += map[y][x];
          label[y][x] = number;
        }
      }
    }
  }
  else if (number == 2)
  {
    for (int y = start.y; y <= end.y; ++y)
    {
      for (int x = end.x; x <= start.x; ++x)
      {
        if (label[y][x] == 5)
          continue;
        if (label[y][x] == 0)
        {
          sum += map[y][x];
          label[y][x] = number;
        }
      }
    }
  }
  else if (number == 3)
  {
    for (int y = end.y; y <= start.y; ++y)
    {
      for (int x = start.x; x <= end.x; ++x)
      {
        if (label[y][x] == 5)
          continue;
        if (label[y][x] == 0)
        {
          sum += map[y][x];
          label[y][x] = number;
        }
      }
    }
  }
  else if(number == 4)
  {
    for (int y = end.y; y <= start.y; ++y)
    {
      for (int x = end.x; x <= start.x; ++x)
      {
        if (label[y][x] == 5)
          continue;
        if (label[y][x] == 0)
        {
          sum += map[y][x];
          label[y][x] = number;
        }
      }
    }
  }
  return sum;
}

int makeFiveArea(int sy, int sx, int sleft, int sright)
{
  INFO top, left, right, bottom;
  top = { sy, sx }; label[top.y][top.x] = 5;
  left = { sy + sleft, sx - sleft }; label[left.y][left.x] = 5;
  right = { sy + sright, sx + sright }; label[right.y][right.x] = 5;
  bottom = { sy + sleft + sright, sx + (sright - sleft) }; label[bottom.y][bottom.x] = 5;
  int nx = top.x;
  for (int y = sy; y < left.y; ++y)
  {
    label[y][nx] = 5;
    nx -= 1;
  }
  nx = top.x;
  for (int y = sy; y < right.y; ++y)
  {
    label[y][nx] = 5;
    nx += 1;
  }
  nx = left.x;
  for (int y = left.y; y < bottom.y; ++y)
  {
    label[y][nx] = 5;
    nx += 1;
  }
  nx = right.x;
  for (int y = right.y; y < bottom.y; ++y)
  {
    label[y][nx] = 5;
    nx -= 1;
  }

  bool stFlag = false;
  for (int y = top.y + 1; y < bottom.y; ++y)
  {
    for (int x = 0; x < n; ++x)
    {
      if (!stFlag && label[y][x] == 5)
      {
        stFlag = true;
      }
      else if (stFlag && label[y][x] == 5)
      {
        stFlag = false;
        break;
      }
      if (stFlag)
      {
        label[y][x] = 5;
      }
    }
  }

  val[1] = findArea({ 0,0 }, { left.y - 1, top.x }, 1);
  val[2] = findArea({ 0,n - 1 }, { right.y, top.x + 1 }, 2);
  val[3] = findArea({ n - 1,0 }, { left.y, bottom.x - 1 }, 3);
  val[4] = findArea({ n - 1,n - 1 }, { right.y + 1, bottom.x }, 4);
  int sum = 0;
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < n; ++x)
    {
      if (label[y][x] == 5 || label[y][x] == 0)
      {
        sum += map[y][x];
      }
    }
  }
  return sum;
}

int main()
{
  scanf("%d", &n);
  for (int y = 0; y < n; ++y)
  {
    for (int x = 0; x < n; ++x)
    {
      scanf("%d", &map[y][x]);
    }
  }
  ret = INF;
  for (int y = 0; y < n - 2; ++y)
  {
    for (int x = 1; x < n - 1; ++x)
    {
      for (int left = 1; left < n; ++left)
      {
        if (x - left < 0)
          break;
        for (int right = 1; right < n; ++right)
        {
          if (x + right >= n)
            break;
          memset(label, 0, sizeof(label));
          val[5] = makeFiveArea(y, x, left, right);
          int maxi = 0, mini = INF;
          maxi = *max_element(val + 1, val + 6);
          mini = *min_element(val + 1, val + 6);
          ret = min(ret, abs(maxi - mini));
        }
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}

#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

struct Point
{
  int x; int y;
};

struct Q
{
  int front, rear;
  Point arr[1000];
  Q()
  {
    front = 0; rear = 0;
  }
  bool is_empty()
  {
    if (rear == front)
      return true;
    else
      return false;
  }
  void push(Point p)
  {
    if ((rear + 1) % 1000 == front)
      return;
    arr[rear] = p;
    rear = ++rear % 1000;
  }
  Point pop()
  {
    if (is_empty())
      return {};
    Point temp = arr[front];
    front = ++front % 1000;
    return temp;
  }
};

char map[300][300];
int check[300][300];
const int dx[] = { +1,+1,0,-1,-1,-1,0,+1 };
const int dy[] = { 0,+1,+1,+1,0,-1,-1,-1 };
int main()
{
  freopen("input.txt", "r", stdin);

  int T; scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases)
  {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        scanf("%c", &map[i][j]);
      }
    }
    
  }
  
  return 0;
}

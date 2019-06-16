#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

typedef struct _node
{
  int col; int row; int area;
}Node;

typedef struct _point
{
  int y; int x;
}Point;

const int dx[] = { 1,0 };
const int dy[] = { 0,1 };
Point q[10000];
int fp, rp;
int N;

Node arr[100];
Node arr2[100];
int map[100][100];
bool visit[100][100];
int ans;

void bfs(int y, int x)
{
  int starty = y;
  int startx = x;

  visit[y][x] = true;
  q[fp].x = x;
  q[fp].y = y;
  fp = (fp + 1) % 10000;
  while (fp != rp)
  {
    int curx = q[rp].x;
    int cury = q[rp].y;
    rp = (rp + 1) % 10000;
    for (int i = 0; i < 2; ++i)
    {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (0 > nx || nx >= N || 0 > ny || ny >= N)
        continue;
      if (map[ny][nx] && !visit[ny][nx])
      {
        q[fp].x = nx;
        q[fp].y = ny;
        fp = (fp + 1) % 10000;
        visit[ny][nx] = true;
      }
    }
  }
  if (fp == 0)
  {
    arr[ans - 1].col = q[10000 - 1].y + 1 - starty;
    arr[ans - 1].row = q[10000 - 1].x + 1 - startx;
    arr[ans - 1].area = arr[ans - 1].col * arr[ans - 1].row;
  }
  else
  {
    arr[ans - 1].col = q[fp - 1].y + 1 - starty;
    arr[ans - 1].row = q[fp - 1].x + 1 - startx;
    arr[ans - 1].area = arr[ans - 1].col * arr[ans - 1].row;
  }
}

void merge(int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low;
  while (i <= mid && j <= high)
  {
    if (arr[i].area < arr[j].area)
      arr2[k++] = arr[i++];
    else
      arr2[k++] = arr[j++]; 
    
  }
  if (i >= mid)
  {
    while (j <= high)
      arr2[k++] = arr[j++];
  }
  if (j >= high)
  {
    while (i <= mid)
      arr2[k++] = arr[i++];
  }
  for (int i = low; i <= high; ++i)
  {
    arr[i] = arr2[i];
  }
}

void mergeSort(int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);

  int T; scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases)
  {
    for (int i = 99; i >= 0; --i)
    {
      for (int j = 99; j >= 0; --j)
      {
        visit[i][j] = false;
      }
    }
    fp = rp = ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        scanf("%d", &map[i][j]);
      }
    }

    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        if (map[i][j] && !visit[i][j])
        {
          ans++;
          bfs(i, j);
        }
      }
    }

    mergeSort(0, ans - 1);

    printf("#%d %d ", cases, ans);
    for (int i = 0; i < ans; ++i)
    {
      printf("%d %d ", arr[i].col, arr[i].row);
    }
    printf("\n");
  }

  return 0;
}

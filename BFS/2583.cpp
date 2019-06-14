#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

typedef struct _point
{
  int x; int y;
}Point;

int N, M, K;
int paper[101][101];
bool visit[101][101];
int area[10001];
Point q[101];
int fp, rp;
int ans;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
void quickSort(int start, int end)
{
  if (start >= end) return;
  int pivot = start;
  int left = start + 1;
  int right = end;
  int temp;
  while (left <= right)
  {
    while (left <= end && area[left] <= area[pivot])
      left++;
    while (right > start && area[right] >= area[pivot])
      right--;
    if (left > right)
    {
      temp = area[right];
      area[right] = area[pivot];
      area[pivot] = temp;
    }
    else
    {
      temp = area[left];
      area[left] = area[right];
      area[right] = temp;
    }
  }
  quickSort(start, right - 1);
  quickSort(right + 1, end);
}

void bfs(int x, int y)
{
  q[fp].x = x;
  q[fp].y = y;
  fp = (fp + 1) % 101;
  
  visit[x][y] = true;
  int count = 1;
  while (fp != rp)
  {
    int curx = q[rp].x;
    int cury = q[rp].y;
    rp = (rp + 1) % 101;
    for (int i = 0; i < 4; ++i)
    {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny < M)
      {
        if (!paper[nx][ny] && !visit[nx][ny])
        {
          visit[nx][ny] = true;
          q[fp].x = nx;
          q[fp].y = ny;
          fp = (fp + 1) % 101;
          count++;
        }
      }
    }
  }
  area[ans - 1] = count;
}

int main()
{
  scanf("%d %d %d", &M, &N, &K);

  for (int i = 0; i < K; ++i)
  {
    int lx, ly, rx, ry;
    scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
    for (int y = ly; y < ry; ++y)
    {
      for (int x = lx; x < rx; ++x)
      {
        paper[x][y] = 1;
      }
    }
  }

  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (!paper[j][i] && !visit[j][i])
      {
        ans++;
        bfs(j,i);
      }
    }    
  }

  quickSort(0, ans - 1);

  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i)
  {
    printf("%d ", area[i]);
  }

  return 0;
}

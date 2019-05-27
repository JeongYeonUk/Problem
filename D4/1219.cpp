#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

const int MAX = 100;

//int first_arr[MAX];
//int second_arr[MAX];
int graph[MAX][2];
int check[MAX];
bool flag;

struct Q
{
  int front, rear;
  int arr[MAX];

  Q()
  {
    front = rear = 0;
  }

  void init_Q()
  {
    front = rear;
  }

  void push(int num)
  {
    if ((rear + 1) % MAX == front)
    {
      //cout << "Queue Overflow";
      printf("Queue Overflow");
      return;
    }
    arr[rear] = num;
    rear = ++rear % MAX;
  }

  int pop()
  {
    if (front == rear)
    {
      //cout << "Queue Underflow";
      printf("Queue Underflow");
      return -1;
    }
    int num = arr[front];
    front = ++front % MAX;
    return num;
  }

  bool empty()
  {
    if (rear == front)
      return true;
    else
      return false;
  }
};

void init()
{
  for (int i = 0; i < MAX; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      graph[i][j] = 0;
    }
    check[i] = 0;
  }
}

void bfs(int start)
{
  check[start] = 1;
  Q q;
  q.push(graph[start][0]);
  q.push(graph[start][1]);
  while (!q.empty())
  {
    int next = q.pop();
    if (next == 99)
    {
      flag = true;
      break;
    }
    if (check[next]) continue;
    check[next] = 1;
    for (int i = 0; i < 2; ++i)
    {
      if (!graph[next][i]) continue;
      q.push(graph[next][i]);
    }
  }
}
int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);

  freopen("input.txt", "r", stdin);

  for (int cases = 1; cases <= 10; ++cases)
  {
    init();
    int T; //cin >> T;
    scanf("%d", &T);
    int way; //cin >> way;
    scanf("%d", &way);
    for (int i = 0; i < way; ++i)
    {
      int a, b; scanf("%d %d", &a, &b);
      if (graph[a][0] != 0)
      {
        graph[a][1] = b;
      }
      else
      {
        graph[a][0] = b;
      }
    }
    flag = false;
    bfs(0);
    printf("#%d ", T);
    if (flag)
      printf("1\n");
    else
      printf("0\n");
  }

  return 0;
}

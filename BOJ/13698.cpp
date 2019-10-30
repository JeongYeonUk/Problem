#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int cup[5];
char input[201];

void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  cup[1] = -1;
  cup[4] = INF;
  scanf("%s", input);
  for (int i = 0; input[i] != NULL; ++i)
  {
    switch (input[i] - 'A')
    {
    case 0:
      swap(cup[1], cup[2]);
      break;
    case 1:
      swap(cup[1], cup[3]);
      break;
    case 2:
      swap(cup[1], cup[4]);
      break;
    case 3:
      swap(cup[2], cup[3]);
      break;
    case 4:
      swap(cup[2], cup[4]);
      break;
    case 5:
      swap(cup[3], cup[4]);
      break;
    default:
      break;
    }
  }
  int maxi = 0, mini = 0;
  for (int i = 1; i < 5; ++i)
  {
    if (cup[i] == -1)
      mini = i;
    if (cup[i] == INF)
      maxi = i;
  }
  printf("%d\n%d\n", mini, maxi);
  return 0;
}

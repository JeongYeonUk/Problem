#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

typedef struct _node
{
  int number;
  char alpha;
  int left;
  int right;
}Node;

Node tree[100];

void inorder(int idx)
{
  if (tree[idx].left != -1)
    inorder(tree[idx].left-1);
  printf("%c", tree[idx].alpha);
  if (tree[idx].right != -1)
    inorder(tree[idx].right-1);
}

int main()
{
  freopen("input.txt", "r", stdin);  
  for (int cases = 1; cases <= 10; ++cases)
  {
    for (int i = 0; i < 100; ++i)
    {
      tree[i].number = tree[i].left = tree[i].right = 0;
      tree[i].alpha = '\0';
    }
    int T; scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
      scanf("%d", &tree[i].number);
      scanf(" %c", &tree[i].alpha);
      if (T >= (i + 1) * 2)
        scanf("%d", &tree[i].left);
      else
        tree[i].left = -1;
      if (T > (i + 1) * 2)
        scanf("%d", &tree[i].right);
      else
        tree[i].right = -1;
    }
    printf("#%d ", cases);
    inorder(0);
    printf("\n");
  }

  return 0;
}

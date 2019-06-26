#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

typedef struct _tree
{
	int type;
	int data;
	char op;
	int left = 0;
	int right = 0;
}Tree;

int solve(Tree* node, int index)
{
	if (node[index].type == 0)
	{
		switch (node[index].op)
		{
		case '+':
			return solve(node, node[index].left) + solve(node, node[index].right);
		case '-':
			return solve(node, node[index].left) - solve(node, node[index].right);
		case '*':
			return solve(node, node[index].left) * solve(node, node[index].right);
		case '/':
			return solve(node, node[index].left) / solve(node, node[index].right);
		default:
			break;
		}
	}
	else
		return node[index].data;
}

int main()
{
	freopen("input.txt", "r", stdin);

	//int T; scanf("%d", &T);
	for (int cases = 1; cases <= 10; ++cases)
	{
		char ch;
		int index;
		int numNode;
		Tree node[2001];
		scanf("%d\n", &numNode);
		for (int i = 0; i < numNode; ++i)
		{
			scanf("%d %c", &index, &ch);
			if (ch == '+' || ch == '*' || ch == '/' || ch == '-')
			{
				node[index].type = 0;
				node[index].op = ch;
				scanf("%d %d\n", &node[index].left, &node[index].right);
			}
			else
			{
				node[index].type = 1;
				node[index].data = (int)(ch - '0');
				while (ch != '\n')
				{
					scanf("%c", &ch);
					if (ch != '\n')
					{
						node[index].data = 10 * node[index].data + (int)(ch - '0');
					}
				}
			}
		}

		printf("#%d %d\n", cases, solve(node, 1));
	}

	return 0;
}

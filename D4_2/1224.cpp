#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

char infix[150];
char prefix[150];
char op[150];
int num[150];
void init()
{
	for (int i = 0; i < 150; ++i)
	{
		infix[i] = '\0';
		prefix[i] = '\0';
		op[i] = '\0';
		num[i] = 0;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);

	//int T; scanf("%d", &T);
	for (int cases = 1; cases <= 11; ++cases)
	{
		init();
		int N; scanf("%d", &N);
		scanf("%s", infix);
		int pre_index = 0;
		int op_index = 0;
		for (int i = 0; infix[i] != 0; ++i)
		{
			char c = infix[i];
			if (c == '(') continue;
			if (0 <= (c - '0') && (c - '0') < 10)
			{
				prefix[pre_index++] = c;
			}
			else if (c == ')')
			{
				prefix[pre_index++] = op[--op_index];
				op[op_index] = '\0';
			}
			else if (c == '+')
			{
				if (op_index == 0)
				{
					op[op_index++] = c;
					continue;
				}
				char temp = op[--op_index];
				op[op_index] = '\0';
				if (temp == '+' || temp == '*')
				{
					prefix[pre_index++] = temp;
				}
				op[op_index++] = c;
			}
			else if (c == '*')
			{
				if (op_index == 0)
				{
					op[op_index++] = c;
					continue;
				}
				while (1)
				{
					if (op_index == 0)
						break;
					char temp = op[--op_index];
					op[op_index] = '\0';
					if (temp == '*')
					{
						prefix[pre_index++] = temp;
					}
					else
					{
						op[op_index++] = temp;
						break;
					}
				}
				op[op_index++] = c;
			}
		}
		pre_index--;
		for (int i = 0; op[i] != 0; ++i)
		{
			prefix[pre_index++] = op[i];
		}
		
		int top = 0;
		for (int i = 0; prefix[i] != 0; ++i)
		{
			char c = prefix[i];
			if ('0' <= c && c <= '9')
			{
				num[top++] = (c - '0');
			}
			else if (c == '+')
			{
				int a = num[--top];
				int b = num[--top];
				int cal = a + b;
				num[top++] = cal;
			}
			else if (c == '*')
			{
				int a = num[--top];
				int b = num[--top];
				int cal = a * b;
				num[top++] = cal;
			}
		}
		printf("#%d %d\n", cases, num[0]);
	}

	return 0;
}

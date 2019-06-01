#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

char infix[150];
char prefix[150];
char stk[150];
int num[150];
void init()
{
	for (int i = 0; i < 150; ++i)
	{
		infix[i] = '\0';
		prefix[i] = '\0';
		stk[i] = '\0';
		num[i] = 0;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);

	//int T; scanf("%d", &T);
	for (int cases = 1; cases <= 10; ++cases)
	{
		init();
		int N; scanf("%d", &N);
		scanf("%s", infix);
		
		int pre_index = 0;
		int stk_index = 0;
		for (int i = 0; infix[i] != 0; ++i)
		{
			char c = infix[i];
			if ('0' <= c && c <= '9')
			{
				prefix[pre_index++] = c;
			}
			else if (c == '(')
			{
				stk[stk_index++] = c;
			}
			else if (c == '+')
			{
				if (stk_index == 0)
					stk[stk_index++] = c;
				else
				{
					while (stk_index != 0)
					{
						if (stk[stk_index - 1] == '+' || stk[stk_index-1] == '*')
						{
							prefix[pre_index++] = stk[stk_index-1];
							stk[--stk_index] = '\0';
						}
						else
						{
							stk[stk_index++] = c;
							break;
						}
					}
				}
			}
			else if (c == '*')
			{
				if (stk_index == 0)
					stk[stk_index++] = c;
				else
				{
					while (stk_index != 0)
					{
						if (stk[stk_index -1] == '*')
						{
							prefix[pre_index++] = stk[stk_index-1];
							stk[--stk_index] = '\0';
						}
						else
						{
							stk[stk_index++] = c;
							break;
						}
					}
				}
			}
			else if (c == ')')
			{
				while (stk[stk_index-1] != '(')
				{
					prefix[pre_index++] = stk[stk_index-1];
					stk[--stk_index] = '\0';
				}
				stk[--stk_index] = '\0';
			}
		}

		for (int i = stk_index - 1; i >= 0; --i)
		{
			prefix[pre_index++] = stk[i];
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

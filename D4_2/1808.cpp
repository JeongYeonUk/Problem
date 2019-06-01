#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

int num[10];
int X;
int answer;
int madeNum[1000001];

void solve()
{
	int val = X;
	int cnt = 0;
	for (int i = X; i > 1; --i)
	{
		while (madeNum[i] > 0)
		{
			if (val % i == 0)
			{
				cnt += 1 + madeNum[i];
				val /= i;
			}
			else
				break;
		}
		if (val == 1)
		{
			answer = cnt;
			return;
		}
	}
	answer = -1;
}

void makeNums(int val, int cnt)
{
	if (cnt > 7)
		return;
	if (val > X)
		return;

	if (cnt > 0)
		madeNum[val] = cnt;
	for (int i = 0; i < 10; ++i)
	{
		if (num[i])
			makeNums(val * 10 + i, cnt + 1);
	}
}

void init()
{
	for (int i = 0; i < 10; ++i)
	{
		num[i] = 0;
	}
	for (int i = 0; i < 1000001; ++i)
	{
		madeNum[i] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		init();
		answer = 0;
		for (int i = 0; i < 10; ++i)
		{
			scanf("%d", &num[i]);
		}
		scanf("%d", &X);

		if (X == 1 && num[1])
			answer = 2;
		else
		{
			makeNums(0, 0);
			solve();
		}
		printf("#%d %d\n", cases, answer);
	}

	return 0;
}

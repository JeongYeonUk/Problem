#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int tc, s, t, a, b, ret, flag;

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &tc);
	for (int cases = 1; cases <= tc; ++cases) 
	{
		flag = ret = 0;
		scanf("%d %d %d %d", &s, &t, &a, &b);
		if (b == 1)
		{
			flag = 1;
			if ((t - s) % a == 0)
				ret = (t - s) / a;
			else
				ret = -1;
		}

		while (!flag)
		{
			if (s >= t)
				break;
			if (!(t % b) && ((t / b) >= s))
				t /= b;
			else
				t -= a;
			ret++;
		}

		printf("#%d ", cases);
		if (s == t || flag)
			printf("%d\n", ret);
		else
			printf("-1\n");
	}

	return 0;
}
//#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

char str[200];

int main()
{
	//freopen("input.txt", "r", stdin);

	//int T; scanf("%d", &T);
	for (int cases = 1; cases <= 10; ++cases)
	{
		int len; scanf("%d", &len);
		scanf("%s", str);
		int result = 0;
		for (int i = 0; i < len; i += 2)
			result += (str[i] - '0');
		printf("#%d %d\n", cases, result);
	}

	return 0;
}

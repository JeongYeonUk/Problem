#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int start = 1, add = 2;
	while (add != 9)
	{
		int cnt = 0;
		for (int i = 1; i <= start; ++i)
		{
			if (start % i == 0)
			{
				cnt++;
			}
		}
		if (cnt >= 500)
			break;
		printf("%d\n", cnt);
		start += add;
		add += 1;
	}
	printf("%d\n", start);
	return 0;
}
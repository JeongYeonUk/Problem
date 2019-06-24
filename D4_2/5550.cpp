#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		int arr[4] = { 0, };
		char input[2501] = { 0, };
		int ans = 0;
		bool flag = true;
		scanf("%s", input);
		for (int i = 0; input[i] != '\0'; ++i)
		{
			switch (input[i])
			{
			case 'c':
				arr[0]++;
				break;
			case 'r':
				arr[0]--, arr[1]++;
				if (arr[0] < 0)
					flag = false;
				break;
			case 'o':
				arr[1]--, arr[2]++;
				if (arr[1] < 0)
					flag = false;
				break;
			case 'a':
				arr[2]--, arr[3]++;
				if (arr[2] < 0)
					flag = false;
				break;
			case 'k':
				arr[3]--;
				if (arr[3] < 0)
					flag = false;
				break;
			default:
				break;
			}
			int temp = (arr[0] + arr[1] + arr[2] + arr[3]);
			if (ans < temp)
				ans = temp;
		}
		if (arr[0] != 0 || arr[1] != 0 || arr[2] != 0 || arr[3] != 0)
			flag = false;
		if (flag)
			printf("#%d %d\n", cases, ans);
		else
			printf("#%d -1\n", cases);
	}

	return 0;
}

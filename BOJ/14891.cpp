#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	char gear[4][9];
	for (int i = 0; i < 4; ++i)
		scanf("%s", gear[i]);
	int k;
	scanf("%d", &k);
	while (k--)
	{
		int target, cmd;
		scanf("%d %d", &target, &cmd);
		--target;
		int move_cmd[4] = { 0, };
		move_cmd[target] = cmd;
		for (int left = target - 1; left >= 0; --left)
		{
			int right = left + 1;
			if (gear[left][2] == gear[right][6])
				break;
			else
				move_cmd[left] = move_cmd[right] * -1;
		}
		for (int right = target + 1; right < 4; ++right)
		{
			int left = right - 1;
			if (gear[right][6] == gear[left][2])
				break;
			else
				move_cmd[right] = move_cmd[left] * -1;
		}

		for (int i = 0; i < 4; ++i)
		{
			if (move_cmd[i] == 1)
			{
				char temp = gear[i][7];
				for (int j = 7; j >= 1; --j)
				{
					gear[i][j] = gear[i][j - 1];
				}
				gear[i][0] = temp;
			}
			else if (move_cmd[i] == -1)
			{
				char temp = gear[i][0];
				for (int j = 0; j < 7; ++j)
				{
					gear[i][j] = gear[i][j + 1];
				}
				gear[i][7] = temp;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (gear[i][0] == '1')
			ret += (1 << i);
	}
	printf("%d\n", ret);
	return 0;
}

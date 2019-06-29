#include <iostream>
#include <cstring>
using namespace std;

const int INF = 987654321;

const char linked[10][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

int clocks[16];

inline int MIN(int a, int b)
{
	return a > b ? b : a;
}

bool areTweleve()
{
	bool flag = true;
	for (int i = 0; i < 16; ++i)
	{
		if (clocks[i] != 12)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void push(int button)
{
	for (int i = 0; i < 16; ++i)
	{
		if (linked[button][i] == 'x')
		{
			clocks[i] += 3;
			if (clocks[i] == 15) clocks[i] = 3;
		}
	}
}

int solve(int button)
{
	if (button == 10)
	{
		return areTweleve() ? 0 : INF;
	}
	int ret = INF;
	for (int i = 0; i < 4; ++i)
	{
		ret = MIN(ret, i + solve(button + 1));
		push(button);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		for (int i = 0; i < 16; ++i)
		{
			cin >> clocks[i];
		}
		int answer = solve(0);
		if (answer != INF)
			cout << answer << '\n';
		else
			cout << "-1\n";
	}

	return 0;
}
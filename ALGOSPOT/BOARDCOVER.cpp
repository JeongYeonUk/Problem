#include <iostream>
#include <cstring>
using namespace std;

const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

int  H, W;
char input[21][21];
int board[21][21];

bool set(int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i)
	{
		int  ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int solve()
{
	int y = -1, x = -1;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (!board[i][j])
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type)
	{
		if (set(y, x, type, 1))
			ret += solve();
		set(y, x, type, -1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		memset(input, 0, sizeof(input));
		memset(board, 0, sizeof(board));
		cin >> H >> W;
		for (int i = 0; i < H; ++i)
		{
			cin >> input[i];
		}
		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				if (input[i][j] == '#')
					board[i][j] = 1;
			}
		}
		int answer = solve();
		cout << answer << '\n';
	}
	return 0;
}
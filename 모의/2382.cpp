#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Bug
{
	int y;
	int x;
	int num;
	int dir;
};

int map[100][100];
int N;
Bug nest[1001];
void init()
{
	for (int i = 0; i < N; ++i)
	{
		map[0][i] = 1;
		map[i][0] = 1;
		map[N - 1][i] = 1;
		map[i][N - 1] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		/*for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				map[i][j] = 0;
			}
		}*/
		memset(map, 0, sizeof(map));
		int M, K; cin >> N >> M >> K;
		init();
		for (int i = 0; i < K; ++i)
		{
			cin >> nest[i].y >> nest[i].x >> nest[i].num >> nest[i].dir;
		}
		while (M--)
		{
			for (int i = 0; i < K; ++i)
			{
				if (nest[i].num == 0)
					continue;
				int direct = nest[i].dir;
				switch (direct)
				{
				case 1:
				{
					nest[i].y -= 1;
					if (map[nest[i].y][nest[i].x] == 1)
					{
						nest[i].dir = 2;
						nest[i].num /= 2;
					}
					break;
				}
				case 2:
				{
					nest[i].y += 1;
					if (map[nest[i].y][nest[i].x] == 1)
					{
						nest[i].dir = 1;
						nest[i].num /= 2;
					}
					break;
				}
				case 3:
				{
					nest[i].x -= 1;
					if (map[nest[i].y][nest[i].x] == 1)
					{
						nest[i].dir = 4;
						nest[i].num /= 2;
					}
					break;
				}
				case 4:
				{
					nest[i].x += 1;
					if (map[nest[i].y][nest[i].x] == 1)
					{
						nest[i].dir = 3;
						nest[i].num /= 2;
					}
					break;
				}
				default:
					break;
				}
			}
			for (int i = 0; i < K - 1; ++i)
			{
				int cX = nest[i].x;
				int cY = nest[i].y;
				vector<int> same;
				same.push_back(i);
				for (int j = i + 1; j < K; ++j)
				{
					if (cX == nest[j].x && cY == nest[j].y)
					{
						same.push_back(j);
					}
				}
				if ((int)same.size() <= 1)
					continue;
				int max = 0;
				int index = 0;
				for (int j = 0; j < same.size(); ++j)
				{
					if (max < nest[same[j]].num)
					{
						max = nest[same[j]].num;
						index = same[j];
					}
				}
				for (int j = 0; j < same.size(); ++j)
				{
					if (same[j] != index)
					{
						nest[index].num += nest[same[j]].num;
						nest[same[j]].dir = 0;
						nest[same[j]].num = 0;
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < K; ++i)
		{
			sum += nest[i].num;
		}
		cout << '#' << cases << ' ' << sum << '\n';
	}

	return 0;
}
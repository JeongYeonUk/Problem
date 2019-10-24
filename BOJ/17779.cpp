#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { -1,1 };
const int dy[] = { 1,1 };

struct INFO
{
	int y, x;
};

int map[20][20];
int label[20][20];
int n, ret;

void solve(int y, int x, int left, int right)
{
	if (y + left + right >= n)
		return;
	memset(label, 0, sizeof(label));
	INFO pos[4];
	pos[0] = { y,x }; // top
	pos[1] = { y + left, x - left }; // left
	pos[2] = { y + right, x + right }; // right
	pos[3] = { y + left + right, x + (right - left) }; // bottom

	label[y][x] = 5;
	for (int i = 1; i <= left; ++i)
	{
		label[y + dy[0] * i][x + dx[0] * i] = 5;
	}
	for (int i = 1; i <= right; ++i)
	{
		label[y + dy[1] * i][x + dx[1] * i] = 5;
	}
	int xx = x + dx[0] * left;
	int yy = y + dy[0] * left;
	for (int i = 1; i <= right; ++i)
	{
		label[yy + dy[1] * i][xx + dx[1] * i] = 5;
	}
	xx = x + dx[1] * right;
	yy = y + dy[1] * right;
	for (int i = 1; i <= left; ++i)
	{
		label[yy + dy[0] * i][xx + dx[0] * i] = 5;
	}

	for (int y = 0; y < pos[1].y; ++y)
	{
		for (int x = 0; x <= pos[0].x; ++x)
		{
			if (label[y][x] == 5)
				break;
			label[y][x] = 1;
		}
	}

	for (int y = 0; y <= pos[2].y; ++y)
	{
		for (int x = n - 1; x > pos[0].x; --x)
		{
			if (label[y][x] == 5)
				break;
			label[y][x] = 2;
		}
	}

	for (int y = pos[1].y; y < n; ++y)
	{
		for (int x = 0; x < pos[3].x; ++x)
		{
			if (label[y][x] == 5)
				break;
			label[y][x] = 3;
		}
	}

	for (int y = pos[2].y + 1; y < n; ++y)
	{
		for (int x = n - 1; x >= pos[3].x; --x)
		{
			if (label[y][x] == 5)
				break;
			label[y][x] = 4;
		}
	}

	int sum[6] = { 0, };
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (label[y][x] == 5 || label[y][x] == 0)
				sum[5] += map[y][x];
			else
				sum[label[y][x]] += map[y][x];
		}
	}
	int maxSum = *max_element(sum + 1, sum + 6);
	int minSum = *min_element(sum + 1, sum + 6);
	ret = min(ret, maxSum - minSum);
}

int main()
{
	scanf("%d", &n);
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &map[y][x]);
		}
	}
	ret = INF;
	for (int y = 0; y < n - 2; ++y)
	{
		for (int x = 1; x < n - 1; ++x)
		{
			for (int left = 1; left < n; ++left)
			{
				if (x - left < 0)
					break;
				for (int right = 1; right < n; ++right)
				{
					if (x + right >= n)
						break;
					solve(y, x, left, right);
				}
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}

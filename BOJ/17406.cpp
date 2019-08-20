#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 51;

struct cal
{
	int r, c, s;
};

int a[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];
cal c[7];
int N, M, K;

void rotate(int r, int c, int s)
{	
	deque<int> vec;
	for (int x = c - s; x <= c + s; ++x)
	{
		vec.push_back(tmp[r - s][x]);
	}
	for (int y = r - s; y <= r + s; ++y)
	{
		if (y == r - s)
			continue;
		vec.push_back(tmp[y][c + s]);
	}
	for (int x = c + s; x >= c - s; --x)
	{
		if (x == c + s)
			continue;
		vec.push_back(tmp[r + s][x]);
	}
	for (int y = r + s; y >= r - s; --y)
	{
		if (y == r + s)
			continue;
		if (y == r - s)
			continue;
		vec.push_back(tmp[y][c - s]);
	}
	int node = vec.back();
	vec.pop_back();
	vec.push_front(node);
	int idx = 0;
	for (int x = c - s; x <= c + s; ++x)
	{
		tmp[r - s][x] = vec[idx++];
	}
	for (int y = r - s; y <= r + s; ++y)
	{
		if (y == r - s)
			continue;
		tmp[y][c + s] = vec[idx++];
	}
	for (int x = c + s; x >= c - s; --x)
	{
		if (x == c + s)
			continue;
		tmp[r + s][x] = vec[idx++];
	}
	for (int y = r + s; y >= r - s; --y)
	{
		if (y == r + s)
			continue;
		if (y == r - s)
			continue;
		tmp[y][c - s] = vec[idx++];
	}

}

int solve()
{
	int ret = INF;
	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			sum += tmp[i][j];
		}
		ret = min(ret, sum);
		sum = 0;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> a[i][j];
		}
	}	
	for (int i = 1; i <= K; ++i)
	{
		cin >> c[i].r >> c[i].c >> c[i].s;
	}

	deque<int> number(K, 0);
	for (int i = 0; i < (int)number.size(); ++i)
	{
		number[i] = i + 1;
	}

	int ret = INF;
	do
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				tmp[i][j] = a[i][j];
			}
		}
		for (int i = 0; i < (int)number.size(); ++i)
		{
			for (int j = 1; j <= c[number[i]].s; ++j)
			{
				rotate(c[number[i]].r, c[number[i]].c, j);
			}
		}

		ret = min(solve(), ret);

	} while (next_permutation(number.begin(), number.end()));

	cout << ret << '\n';

	return 0;
}

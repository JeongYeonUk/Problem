#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct INFO
{
	int index, val;
};

struct cmp
{
	bool operator()(INFO a, INFO b)
	{
		if (a.val == b.val)
			return a.index > b.index;
		return a.val > b.val;
	}
};

int cnt[101];
int a[101][101];
int r, c, k, ret;
int curR, curC;

void calR()
{	
	int max_val = 0;
	int max_idx = 0;
	int idx = 0;
	for (int y = 1; y <= curR; ++y)
	{
		priority_queue<INFO, vector<INFO>, cmp> pq;
		max_val = 0;
		idx = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int x = 1; x <= curC; ++x)
		{			
			if (max_val < a[y][x])
				max_val = a[y][x];
			cnt[a[y][x]]++;
		}
		for (int i = 1; i <= max_val; ++i)
		{
			if (cnt[i] == 0)
				continue;
			pq.push({ i, cnt[i] });
		}
		if (max_idx < (pq.size() << 1))
			max_idx = (pq.size() << 1);
		if (max_idx > 100)
			max_idx = 100;
		for (int i = 1; i <= 100; i += 2)
		{
			if (!pq.empty())
			{
				INFO cur = pq.top(); pq.pop();
				a[y][i] = cur.index;
				a[y][i + 1] = cur.val;
			}
			else
			{
				a[y][i] = 0;
				a[y][i + 1] = 0;
			}
		}
	}
	curC = max_idx;
}

void calC()
{
	int max_val = 0;
	int max_idx = 0;
	int idx = 0;
	for (int x = 1; x <= curC; ++x)
	{
		priority_queue<INFO, vector<INFO>, cmp> pq;
		max_val = 0;
		idx = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int y = 1; y <= curR; ++y)
		{			
			if (max_val < a[y][x])
				max_val = a[y][x];
			cnt[a[y][x]]++;
		}
		for (int i = 1; i <= max_val; ++i)
		{
			if (cnt[i] == 0)
				continue;
			pq.push({ i, cnt[i] });
		}
		if (max_idx < (pq.size() << 1))
			max_idx = (pq.size() << 1);
		if (max_idx > 100)
			max_idx = 100;
		for (int i = 1; i <= 100; i += 2)
		{
			if (!pq.empty())
			{
				INFO cur = pq.top(); pq.pop();
				a[i][x] = cur.index;
				a[i + 1][x] = cur.val;
			}
			else
			{
				a[i][x] = 0;
				a[i + 1][x] = 0;
			}
		}
	}
	curR = max_idx;
}

int main()
{
	scanf("%d %d %d", &r, &c, &k);
	curR = curC = 3;
	for (int y = 1; y <= curR; ++y)
	{
		for (int x = 1; x <= curC; ++x)
		{
			scanf("%d", &a[y][x]);
		}
	}
	if (a[r][c] == k)
	{
		printf("0\n");
		return 0;
	}
	while (true)
	{
		if (ret > 100)
		{
			ret = -1;
			break;
		}
		if (a[r][c] == k)
			break;
		if (curR >= curC)
			calR();
		else
			calC();
		++ret;
	}
	printf("%d\n", ret);
	return 0;
}

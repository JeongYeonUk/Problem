#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 0,0,0,-1,1 };
const int dy[] = { 0,1,-1,0,0 };
struct INFO
{
	int x, y, dir;
};

int map[13][13];
vector<int> v[13][13];
INFO chess[11];
int n, k, ret;

// 1 : red
// 2 : blue
void move_chess(int start)
{		
	INFO& cur = chess[start];
	if (v[cur.x][cur.y][0] != start)
		return;
	vector<int> temp;
	bool flag = false;
	while (!flag)
	{
		if (v[cur.x][cur.y].back() == start)
			flag = true;
		temp.push_back(v[cur.x][cur.y].back());
		v[cur.x][cur.y].pop_back();
	}
	reverse(temp.begin(), temp.end());

	INFO next;
	next.y = cur.y + dy[cur.dir];
	next.x = cur.x + dx[cur.dir];
	if (next.x <= 0 || next.y <= 0 || next.x > n || next.y > n || map[next.x][next.y] == 2)
	{
		switch (cur.dir)
		{
		case 1:
			cur.dir += 1;
			break;
		case 2:
			cur.dir -= 1;
			break;
		case 3:
			cur.dir += 1;
			break;
		case 4:
			cur.dir -= 1;
			break;
		default:
			break;
		}
		next.y = cur.y + dy[cur.dir];
		next.x = cur.x + dx[cur.dir];
		if (next.x <= 0 || next.y <= 0 || next.x > n || next.y > n || map[next.x][next.y] == 2)
		{
			for (int i = 0; i < (int)temp.size(); ++i)
			{
				v[cur.x][cur.y].push_back(temp[i]);
			}
			return;
		}
	}

	// map is red
	if (map[next.x][next.y] == 1)
	{
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < (int)temp.size(); ++i)
		{
			v[next.x][next.y].push_back(temp[i]);
		}
	}
	// map is non - red
	else if (map[next.x][next.y] == 0)
	{
		for (int i = 0; i < (int)temp.size(); ++i)
		{
			v[next.x][next.y].push_back(temp[i]);
		}
	}

	for (int i = 0; i < (int)temp.size(); ++i)
	{
		chess[temp[i]].y = next.y;
		chess[temp[i]].x = next.x;
	}
	
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int x = 1; x <= n; ++x)
	{
		for (int y = 1; y <= n; ++y)
		{
			scanf("%d", &map[x][y]);
		}
	}
	for (int i = 1; i <= k; ++i)
	{
		int x, y, dir;
		scanf("%d %d %d", &x, &y, &dir);
		chess[i].x = x;
		chess[i].y = y;
		chess[i].dir = dir;
		v[chess[i].x][chess[i].y].push_back(i);
	}
	ret = -1;
	for (int i = 1; i <= 1000; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			move_chess(j);
			for (int x = 1; x <= n; ++x)
			{
				for (int y = 1; y <= n; ++y)
				{
					if (v[x][y].size() >= 4)
					{
						printf("%d\n", i);
						return 0;
					}
				}
			}
		}	
	}
	printf("%d\n", ret);
	return 0;
}

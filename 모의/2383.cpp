#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

using Point = pair<int, int>;

int n, ans;
int map[10][10];
int dir[10];

vector<Point> pos_stairs;
vector<int> time_stairs;
vector<Point> pos_people;

void solve()
{
	int time = 0;
	int size = pos_people.size();
	int to_exit_people = size;

	vector<int> people;
	queue<int> stairs[2];

	for (int i = 0; i < size; ++i)
	{
		int x, y;
		x = abs(pos_people[i].first - pos_stairs[dir[i]].first);
		y = abs(pos_people[i].second - pos_stairs[dir[i]].second);
		people.push_back(x + y + 1);
	}
	while (to_exit_people)
	{
		time++;
		for (int i = 0; i < size; ++i)
		{
			if (people[i] == -1)
				continue;
			else if (people[i] - 1 == 0)
			{
				if (stairs[dir[i]].size() < 3)
				{
					stairs[dir[i]].push(time_stairs[dir[i]]);
					people[i] = -1;
				}
			}
			else
				people[i]--;
		}
		int queue_size = stairs[0].size();
		while (queue_size--)
		{
			int top = stairs[0].front();
			stairs[0].pop();
			top--;
			if (top == 0)
				to_exit_people--;
			else
				stairs[0].push(top);
		}
		queue_size = stairs[1].size();
		while (queue_size--)
		{
			int top = stairs[1].front();
			stairs[1].pop();
			top--;
			if (top == 0)
				to_exit_people--;
			else
				stairs[1].push(top);
		}
	}
	ans = ans > time ? time : ans;
}

void dfs(int idx)
{
	if (idx == pos_people.size())
		solve();
	else
		for (int i = 0; i < 2; ++i)
		{
			dir[idx] = i;
			dfs(idx + 1);
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> n;
		ans = 2e9;
		memset(map, 0, sizeof(map));
		memset(dir, 0, sizeof(dir));
		pos_stairs.clear();
		time_stairs.clear();
		pos_people.clear();

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
					pos_people.push_back({ i,j });
				else if (map[i][j] > 1)
				{
					pos_stairs.push_back({ i,j });
					time_stairs.push_back(map[i][j]);
				}
			}
		}
		dfs(0);

		cout << '#' << cases << ' ' << ans + 1 << '\n';
	}

	return 0;
}
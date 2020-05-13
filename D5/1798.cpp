#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321
#define MAX_TIME 540

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, ans;
int adj[40][40];
int play[40];
int satis[40];
bool used[40];
int airport;

vector<int> hotel, trip, path, ans_path;

void init()
{
	ans = 0;
	ans_path.clear();
	hotel.clear();
	trip.clear();
}

void solve(int cur, int s_sum, int day, int t_sum)
{
	if (cur == airport)
	{
		if (ans < s_sum)
		{
			ans = s_sum;
			ans_path = path;
		}
		return;
	}

	if (day == 0) return;

	bool flag = false;
	for (int next = 0, size = (int)trip.size(); next < size; ++next)
	{
		if (used[trip[next]]) continue;

		if (t_sum + play[trip[next]] + adj[cur][trip[next]] < MAX_TIME)
		{
			used[trip[next]] = true;
			path.push_back(trip[next]);
			solve(trip[next], s_sum + satis[trip[next]], day, t_sum + play[trip[next]] + adj[cur][trip[next]]);
			path.pop_back();
			used[trip[next]] = false;
			flag = true;
		}
	}

	if (!flag)
	{
		if (day == 1)
		{
			if (t_sum + adj[cur][airport] <= MAX_TIME)
			{
				path.push_back(airport);
				solve(airport, s_sum, day - 1, 0);
				path.pop_back();
			}
		}
		else
		{
			for (int i = 0, size = (int)hotel.size(); i < size; ++i)
			{
				if (t_sum + adj[cur][hotel[i]] <= MAX_TIME)
				{
					path.push_back(hotel[i]);
					solve(hotel[i], s_sum, day - 1, 0);
					path.pop_back();
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		init();
		cin >> N >> M;
		for (int i = 1; i < N; ++i)
		{
			for (int j = i + 1; j <= N; ++j)
			{
				int time; cin >> time;
				adj[i][j] = adj[j][i] = time;
			}
		}
		
		for (int i = 1; i <= N; ++i)
		{
			char c; cin >> c;
			if (c == 'A') airport = i;
			else if (c == 'H') hotel.push_back(i);
			else if (c == 'P')
			{
				cin >> play[i] >> satis[i];
				trip.push_back(i);
			}
		}

		for (int i = 0, size = (int)trip.size(); i < size; ++i)
		{
			if (play[trip[i]] + adj[airport][trip[i]] < MAX_TIME)
			{
				used[trip[i]] = true;
				path.push_back(trip[i]);
				solve(trip[i], satis[trip[i]], M, play[trip[i]] + adj[airport][trip[i]]);
				path.pop_back();
				used[trip[i]] = false;
			}
		}

		if (ans == 0)
			cout << "#" << t << " " << ans << endl;
		else
		{
			cout << "#" << t << " " << ans;
			for (int i = 0, size = (int)ans_path.size(); i < size; ++i)
			{
				cout << ' ' << ans_path[i];
			}
			cout << endl;
		}
	}

	return 0;
}

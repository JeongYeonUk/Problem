#include <iostream>
#include  <cstring>
using namespace std;

int areFriend[10][10];
bool visit[10];
int n;
int solve()
{
	int firstFree = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!visit[i])
		{
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int next = firstFree + 1; next < n; ++next)
	{
		if (!visit[next] && areFriend[firstFree][next])
		{
			visit[next] = visit[firstFree] = true;
			ret += solve();
			visit[next] = visit[firstFree] = false;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		memset(areFriend, 0, sizeof(areFriend));
		memset(visit, 0, sizeof(visit));
		int m; cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b; cin >> a >> b;
			areFriend[a][b] = areFriend[b][a] = 1;
		}
		int answer = solve();
		cout << answer << '\n';
	}


	return 0;
}
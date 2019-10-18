#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int person[10];
vector<int> adj[10];
int pick[10];
int n, ret;
vector<int> a, b;
bool visita[10], visitb[10];
void aConti(int x)
{
	if (visita[x])
		return;
	visita[x] = true;
	for (int i = 0; i < (int)adj[x].size(); ++i)
	{
		if (!visita[adj[x][i]] && pick[adj[x][i]])
			aConti(adj[x][i]);
	}
}

void bConti(int x)
{
	if (visitb[x])
		return;
	visitb[x] = true;
	for (int i = 0; i < (int)adj[x].size(); ++i)
	{
		if (!visitb[adj[x][i]] && !pick[adj[x][i]])
			bConti(adj[x][i]);
	}
}

void dfs(int cur, int pick_count, int goal)
{
	if (pick_count == goal)
	{
		int A = 0, B = 0;
		a.clear(); b.clear();
		memset(visita, false, sizeof(visita));
		memset(visitb, false, sizeof(visitb));
		for (int i = 0; i < n; ++i)
		{
			if (pick[i] == 1)
			{
				a.push_back(i);
				A += person[i];
			}
			else
			{
				b.push_back(i);
				B += person[i];
			}
		}
		aConti(a[0]);
		bool ok = true;
		for (int i = 0; i < (int)a.size(); ++i)
		{
			if (!visita[a[i]])
			{
				ok = false;
				break;
			}
		}
		if (!ok) return;
		bConti(b[0]);
		for (int i = 0; i < (int)b.size(); ++i)
		{
			if (!visitb[b[i]])
			{
				ok = false;
				break;
			}
		}
		if (!ok) return;

		if (ret > abs(A - B))
			ret = abs(A - B);		
		return;
	}
	for (int i = cur; i < n; ++i)
	{
		pick[i] = 1;
		dfs(cur + 1, pick_count + 1, goal);
		pick[i] = 0;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &person[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		int cnt; scanf("%d", &cnt);
		for (int j = 0; j < cnt; ++j)
		{
			int x;
			scanf("%d", &x);
			adj[i].push_back(x - 1);
		}
	}
	ret = INF;
	for (int i = 1; i <= n/2; ++i)
	{

		dfs(0,0, i);
	}
	if (ret == INF) ret = -1;
	printf("%d\n", ret);
	return 0;
}

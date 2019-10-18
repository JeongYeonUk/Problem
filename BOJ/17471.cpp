#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int n, ret;
int person[10];
vector<int> adj[10];
int chka[10], chkb[10];
int visita[10], visitb[10];

void goa(int x)
{
	if (visita[x])
		return;
	visita[x] = true;
	for (int i = 0; i < (int)adj[x].size(); ++i)
	{
		int y = adj[x][i];
		if (chka[y] && !visita[y])
			goa(y);
	}
}

void gob(int x)
{
	if (visitb[x])
		return;
	visitb[x] = true;
	for (int i = 0; i < (int)adj[x].size(); ++i)
	{
		int y = adj[x][i];
		if (chkb[y] && !visitb[y])
			gob(y);
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
		int num; scanf("%d", &num);
		for (int j = 0; j < num; ++j)
		{
			int x; scanf("%d", &x);
			adj[i].push_back(x - 1);
		}
	}

	// solve
	int asum = 0, bsum = 0;
	ret = -1;
	for (int i = 1; i < (1 << n) - 1; ++i)
	{
		asum = bsum = 0;
		memset(chka, false, sizeof(chka));
		memset(chkb, false, sizeof(chkb));
		memset(visita, false, sizeof(visita));
		memset(visitb, false, sizeof(visitb));
		vector<int> a, b;
		for (int j = 0; j < n; ++j)
		{			
			if (i & (1 << j))
			{
				a.push_back(j);
				asum += person[j];
				chka[j] = true;
			}
			else
			{
				b.push_back(j);
				bsum += person[j];
				chkb[j] = true;
			}
		}
		goa(a[0]);
		bool ok = true;
		for (int i = 0; i < (int)a.size(); ++i)
		{
			if (!visita[a[i]])
			{
				ok = false;
				break;
			}
		}
		if (!ok) continue;

		gob(b[0]);
		for (int i = 0; i < (int)b.size(); ++i)
		{
			if (!visitb[b[i]])
			{
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		int candi = abs(asum - bsum);
		if (ret == -1 || ret > candi)
			ret = candi;
	}
	printf("%d\n", ret);
	return 0;
}

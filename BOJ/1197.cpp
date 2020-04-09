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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 10000 + 1;

struct Edge
{
	ll s, e, x;
	bool operator<(const Edge& rhs) const
	{
		return x < rhs.x;
	}
};

int p[MAX];
int d[MAX];
int V, E;
vector<Edge> edge;
void make_set()
{
	for (int v = 1; v <= V; ++v)
	{
		p[v] = v;
		d[v] = 1;
	}
}

int find_p(int x)
{
	return x == p[x] ? x : p[x] = find_p(p[x]);
	/*if (x == p[x])
		return x;
	else
		return p[x] = find_p(p[x]);*/
}

bool same_p(int x, int y)
{
	x = find_p(x);
	y = find_p(y);
	
	return x == y;
}

void merge(int x, int y)
{
	x = find_p(x);
	y = find_p(y);

	if (x == y) return;

	if (d[x] > d[y])
		swap(x, y);

	p[x] = y;

	if (d[x] == d[y])
		d[y]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> V >> E;
	for (int e = 0; e < E; ++e)
	{
		int a, b, c; cin >> a >> b >> c;
		edge.push_back(Edge{ a,b,c });
	}

	make_set();

	sort(edge.begin(), edge.end());

	ll ans = 0;
	for (Edge e : edge)
	{
		if (!same_p(e.s, e.e))
		{
			merge(e.s, e.e);
			ans += e.x;
		}
	}

	cout << ans << endl;

	return 0;
}

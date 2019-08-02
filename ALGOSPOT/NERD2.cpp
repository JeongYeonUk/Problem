#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;

const int INF = 0x7FFFFFFF;

map<int, int> coords;

bool isDominated(int x, int y)
{
	mii::iterator it = coords.lower_bound(x);
	if (it == coords.end())
		return false;
	return y < it->second;
}

void removeDominated(int x, int y)
{
	mii::iterator it = coords.lower_bound(x);
	if (it == coords.begin())
		return;
	--it;
	while (true)
	{
		if (it->second > y)
			break;
		if (it == coords.begin())
		{
			coords.erase(it);
			break;
		}
		else
		{
			mii::iterator tmp = it;
			--tmp;
			coords.erase(it);
			it = tmp;
		}
	}
}

int registered(int x, int y)
{
	if (isDominated(x, y))
		return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N; cin >> N;
		coords.clear();
		int ret = 0;
		for (int j = 0; j < N; ++j)
		{
			int x, y; cin >> x >> y;
			ret += registered(x, y);
		}
		cout << ret << '\n';
	}

	return 0;
}

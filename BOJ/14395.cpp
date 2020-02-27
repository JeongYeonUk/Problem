#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct INFO {
	ll now;
	string oper;
};


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	ll s, t;
	cin >> s >> t;

	if (s == t) {
		cout << 0 << endl;
		return 0;
	}

	set<ll> visit;
	queue<INFO> q;
	q.push({ s, "" });
	visit.insert(s);
	bool flag = true;
	while (!q.empty()) {
		ll now = q.front().now; string oper = q.front().oper;
		q.pop();
		if (now == t) {
			cout << oper << endl;
			return 0;
		}

		ll tmp = now * now;

		if (tmp <= t && (visit.find(tmp) == visit.end())) {
			q.push({ tmp, oper + '*' });
			visit.insert(tmp);
		}

		tmp = now << 1;

		if (tmp <= t && (visit.find(tmp) == visit.end())) {
			q.push({ tmp, oper + '+' });
			visit.insert(tmp);
		}

		if (flag) {
			q.push({ 1, oper + '/' });
			flag = false;
		}
	}
	cout << -1 << endl;
	return 0;
}

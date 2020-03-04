#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;

/*
3
2
Alex Tom
Paul Alex
4
A B
B C
C D
D A
3
z d
d u_i
z u_i

Yes
Yes
No
*/

#define endl '\n'
#define rint register int
#define ll long long
#define INF 987654321
#define abs(x) (x > 0 ? x : -x)
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)
#define MAX 200 + 5

map<string, int> m;
int syn[MAX][MAX];
int chk[MAX];
int pSize, k, idx;
bool flag;

bool check() {
	for (rint i = 0; i < pSize; ++i) {
		for (rint j = i + 1; j < pSize; ++j) {
			if (syn[i][j] && (chk[i] == chk[j]))
				return false;
		}
	}
	return true;
}

void bfs(int ss) {
	bool visit[MAX] = { false, };
	queue<int> q;
	q.push(ss);
	chk[ss] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (rint next = 0; next < pSize; ++next) {
			if (cur == next)
				continue;
			if (visit[next])
				continue;
			if (syn[cur][next]) {
				if (chk[next] == -1)
					chk[next] = chk[cur] ^ 1;
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int tc; cin >> tc;
	for (rint t = 1; t <= tc; ++t) {
		k; cin >> k;
		idx = 0;
		m.clear();
		memset(syn, 0, sizeof(syn));
		memset(chk, -1, sizeof(chk));

		for (rint i = 0; i < k; ++i) {
			string a, b;
			cin >> a >> b;

			// Duplicate check
			// if second <- true == insert success
			// if second <- false == insert fail ( Duplicate key )
			if (m.insert({ a,idx }).second) {
				idx++;
			}
			if (m.insert({ b,idx }).second) {
				idx++;
			}

			syn[m[a]][m[b]] = 1;
			syn[m[b]][m[a]] = 1;			
		}
		pSize = m.size();
		for (rint i = 0; i < pSize; ++i) {
			if (chk[i] == -1)
				bfs(i);
		}

		flag = check();

		cout << '#' << t << ' ';
		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
		
	}
	
	return 0;
}

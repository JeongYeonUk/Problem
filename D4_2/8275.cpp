#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'
#define rint register int
#define ll long long
#define INF 987654321
#define abs(x) (x > 0 ? x : -x)
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)
#define MAX 7 + 5

struct INFO {
	int l, r, s;
};

int N, X, M;
int cnt[MAX], sel[MAX], visit[MAX];
bool flag;
string ans;
vector<int> check[MAX];
vector<INFO> info;

void init() {
	memset(cnt, 0, sizeof(cnt));
	memset(sel, 0, sizeof(sel));
	memset(visit, 0, sizeof(visit));
	ans = "";
	flag = false;
	info.clear();
	for (rint i = 0; i < MAX; ++i) {
		check[i].clear();
	}
}

bool check2() {
	for (rint i = 0; i < M; ++i) {
		INFO cur = info[i];
		int temp = 0;
		for (rint idx = cur.l; idx <= cur.r; ++idx) {
			temp += sel[idx];
		}
		if (temp != cur.s)
			return false;
	}
	return true;
}

bool check1(int num) {
	int size = (int)check[num].size();
	for (rint i = 0; i < size; ++i) {
		INFO cur = info[check[num][i]];
		int temp = 0;
		for (rint idx = cur.l; idx <= cur.r; ++idx) {
			temp += sel[idx];
		}
		if (temp > cur.s)
			return false;
	}
	return true;
}

void dfs(int idx) {
	if (flag)
		return;
	if (idx == 0) {
		if (check2()) {
			for (rint i = 1; i <= N; ++i) {
				ans += to_string(sel[i]) + " ";
				flag = true;
			}
		}
		return;
	}

	for (rint i = cnt[idx]; i >= 0; --i) {
		sel[idx] = i;
		if (check1(idx)) {
			dfs(idx - 1);
		}
		sel[idx] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int tc; cin >> tc;
	for (rint t = 1; t <= tc; ++t) {
		init();
		cin >> N >> X >> M;
		for (rint i = 0; i < MAX; ++i)
			cnt[i] = X;
		int l, r, s;
		for (rint i = 0; i < M; ++i) {
			cin >> l >> r >> s;
			 info.push_back({ l,r,s });
		}

		for (rint i = 0; i < M; ++i) {
			INFO cur = info[i];
			int temp = X;
			if (cur.s < temp)
				temp = cur.s;
			for (rint idx = cur.l; idx <= cur.r; ++idx) {
				cnt[idx] = temp;
				check[idx].push_back(i);
			}
		}
		dfs(N);

		if (ans == "")
			ans = "-1";
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define DEL 99999

typedef pair<int, int> pii;

int num[55][55];
int bias[55];
int N, M, T;

// i번째 원판의 j번째 위치 녀석 값 가져오기
int get_num(int i, int j){
	j += bias[i];
	while (j < 0) {
		j += M;
	}
	j %= M;
	return num[i][j];
}

void set_num(int i, int j, int v) {
	j += bias[i];
	while (j < 0) {
		j += M;
	}
	j %= M;
	num[i][j] = v;
}

void solve() {
	bool changed = false;
	vector<pii> del;
	del.clear();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a = get_num(i, j);
			int b = get_num(i, j + 1);
			if (a != DEL && b != DEL && a == b) {
				del.push_back({ i,j });
				del.push_back({ i,j + 1 });
				changed = true;
			}
		}
	}

	for (int i = 0; i + 1 < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a = get_num(i, j);
			int b = get_num(i + 1, j);
			if (a != DEL && b != DEL && a == b) {
				del.push_back({ i,j });
				del.push_back({ i + 1,j });
				changed = true;
			}
		}
	}

	for (auto p : del) {
		set_num(p.first, p.second, DEL);
	}

	if (changed)
		return;

	int cnt, sum;
	cnt = sum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (num[i][j] != DEL) {
				cnt++;
				sum += num[i][j];
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (num[i][j] != DEL) {
				if (num[i][j] * cnt > sum) {
					num[i][j]--;
				}
				else if (num[i][j] * cnt < sum) {
					num[i][j]++;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> num[i][j];
		}
	}

	while (T--) {
		int x, d, k;
		cin >> x >> d >> k;
		int v = x;
		int shift = k * (d == 0 ? -1 : 1);
		while (v <= N) {
			bias[v - 1] += shift;
			v += x;
		}
		solve();
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (num[i][j] != DEL)
				ans += num[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
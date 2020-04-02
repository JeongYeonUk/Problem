#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
#define X second
#define Y first

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;

bool cmp(double a, double b) {
	return a > b;
}
int N, K;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cout << fixed;
	cout.setf(ios::showpoint);
	cout.precision(6);

	//freopen("input.txt", "r", stdin);

	/*
	가장 효율이 큰 K개의 강의를 뽑아낸 후
	뽑아낸 K개의 강의중 가장 효율이 낮은 강의 부터 듣는다.
	*/


	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		vector<double> v;
		cin >> N >> K;
		for (int i = 0; i < N; ++i) {
			double num; cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(), cmp);
		double ans = 0.0;
		for (int i = K - 1; i >= 0; --i) {
			ans = (ans + v[i]) / 2;
		}
		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}

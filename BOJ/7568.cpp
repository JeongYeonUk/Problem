#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

bool check(pii a, pii b) {
	return a.first < b.first && a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	vector<pii> person;

	cin >> N;

	int x, y;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		person.push_back(make_pair(x, y));
	}

	vector<int> ans;

	for (int i = 0; i < N; ++i) {
		int candi = 1;
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			if (check(person[i], person[j])) candi++;
		}
		ans.push_back(candi);
	}

	for (int a : ans) {
		cout << a << ' ';
	}

	return 0;
}

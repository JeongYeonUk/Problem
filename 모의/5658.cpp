#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int pre[256];
int N, K;
string str;

bool cmp(ll a, ll b) {
	return a > b;
}

ll toDecimal(const string& s) {
	ll mul = 1;
	ll ans = 0;
	int len = (int)s.size();

	while (len > 0) {
		ans += mul * pre[s[--len]];
		mul <<= 4;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	pre['1'] = 1;
	pre['2'] = 2;
	pre['3'] = 3;
	pre['4'] = 4;
	pre['5'] = 5;
	pre['6'] = 6;
	pre['7'] = 7;
	pre['8'] = 8;
	pre['9'] = 9;
	pre['A'] = 10;
	pre['B'] = 11;
	pre['C'] = 12;
	pre['D'] = 13;
	pre['E'] = 14;
	pre['F'] = 15;

	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N >> K;
		cin >> str;
		
		int len = (N >> 2);

		// 문자열 탐색하면서 만들어진 문자를 십진수로 변경
		vector<ll> vec;
		for (int i = 0, size = (int)str.size(); i < size; ++i) {
			string tmp = "";
			for (int j = 0; j < len; ++j) {
				tmp += str[(i + j) % size];
			}
			vec.push_back(toDecimal(tmp));
		}

		sort(vec.begin(), vec.end(), cmp);
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		/*for (auto v : vec) {
			cout << v << " ";
		}
		cout << endl;*/
		cout << '#' << t << ' ' << vec[K - 1] << endl;
	}

	return 0;
}

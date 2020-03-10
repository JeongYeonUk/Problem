#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

#define endl '\n'

const int INF = 987654321;

vector<string> s;
string str;
int N;

bool cmp(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		s.clear();
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> str;
			s.push_back(str);
		}
		sort(s.begin(), s.end(), cmp);
		s.erase(unique(s.begin(), s.end()), s.end());
		cout << "#" << t << endl;
		for (int i = 0; i < s.size(); ++i) {
			cout << s[i] << endl;
		}
	}

	return 0;
}
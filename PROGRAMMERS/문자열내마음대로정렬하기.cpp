#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int N;

bool cmp(string a, string b) {
	if (a[N] == b[N]) {
		return a < b;
	}
	else {
		return a[N] < b[N];
	}
}

vector<string> solution(vector<string>s, int n)
{
	vector<string> answer = s;
	N = n;
	sort(answer.begin(), answer.end(), cmp);
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<string> s = { "abzcd","cdzab","abzfg","abzaa","abzbb", "bbzaa" };
	int n = 2;
	vector<string> ret = solution(s,n);
	for (auto elem : ret) {
		cout << elem << ' ';
	}

	return 0;
}

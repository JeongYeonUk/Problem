#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> get_pi(const string& p)
{
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; ++i)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
		{
			pi[i] = ++j;
		}
	}
	return pi;
}

vector<int> kmp(const string& s, const string& p)
{
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	auto pi = get_pi(p);
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else
			{
				++j;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	string s, p;
	getline(cin, s);
	getline(cin, p);

	auto matched = kmp(s, p);
	cout << ((int)matched.size() ? 1 : 0) << endl;

	return 0;
}

#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	int idx = 0;
	vector<string> v;
	while (idx != len)
	{
		v.push_back(string(s.begin() + idx, s.end()));
		idx++;
	}
	sort(v.begin(), v.end());
	for (auto out : v)
	{
		cout << out << '\n';
	}
	return 0;
}

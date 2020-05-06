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

string str1, str2;

ll toDeci(const string& str, int type)
{
	ll candi = 0;
	ll val = 1;

	for (int i = (int)str.size() - 1; i >= 0; --i)
	{
		candi += (str[i] - '0') * val;
		val *= type;
	}

	return candi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int T; cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		cin >> str1 >> str2;

		vector<ll> candi1, candi2;
		for (int i = 0, size = (int)str1.size(); i < size; ++i)
		{
			str1[i] = (str1[i] == '0' ? '1' : '0');
			candi1.push_back(toDeci(str1, 2));
			str1[i] = (str1[i] == '0' ? '1' : '0');
		}

		for (int i = 0, size = (int)str2.size(); i < size; ++i)
		{
			char origin = str2[i];

			switch (str2[i])
			{
			case '0':
				str2[i] = '1';
				candi2.push_back(toDeci(str2, 3));
				str2[i] = '2';
				candi2.push_back(toDeci(str2, 3));
				break;
			case '1':
				str2[i] = '0';
				candi2.push_back(toDeci(str2, 3));
				str2[i] = '2';
				candi2.push_back(toDeci(str2, 3));
				break;
			case '2':
				str2[i] = '0';
				candi2.push_back(toDeci(str2, 3));
				str2[i] = '1';
				candi2.push_back(toDeci(str2, 3));
				break;
			default:
				break;
			}

			str2[i] = origin;
		}

		ll ans = 0;
		for (int i = 0, size1 = (int)candi1.size(); i < size1; ++i)
		{
			bool flag = false;
			for (int j = 0, size2 = (int)candi2.size(); j < size2; ++j)
			{
				if (candi1[i] == candi2[j])
				{
					ans = candi1[i];
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}

		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int code[50][100];
int N, M;

bool oneToken(int index, string& str)
{
	int sum = 0;
	for (int j = 0; j < M; ++j)
	{
		code[index][j] = (str[j] - '0');
		sum += code[index][j];
	}
	if (sum)
		return true;
	else
		return false;
}

int solve(string& str)
{
	vector<string> v;
	int count = 0;
	int length = (int)str.length();
	string s;
	for (int i = 0; i < length; ++i)
	{
		s += str[i];
		if (s.length() == 7)
		{
			v.push_back(s);
			s = "";
		}
	}
	length = (int)v.size();
	int num = 0;
	int arr[8] = { 0, };
	for (int i = 0; i < length; ++i)
	{
		int temp = 0;
		for (int j = 0; j < 7; ++j)
		{
			if (temp != (v[i][j] - '0'))
			{
				num += count;
				count = 0;
			}
			temp = (v[i][j] - '0');
			count++;
		}
		arr[i] = num;
	}
	int ret = (arr[0] + arr[2] + arr[4] + arr[6]) * 3;
	ret += arr[1] + arr[3] + arr[5] + arr[7];
	int ans = 0;
	if (ret % 10 == 0)
	{
		for (int i = 0; i < 8; ++i)
		{
			ans += arr[i];
		}
	}
	return ans;
}

int check(int index)
{
	int temp = 0;
	int ans = 0;
	while (true)
	{
		if (((M - 56) + 1) == temp)
			break;
		string str;
		string s;
		for (int i = temp; i < M; ++i)
		{
			str += (char)(code[index][i] + 48);
			if (str.length() == 7)
			{
				int sum = 0;
				for (int i = 0; i < 7; ++i)
				{
					sum += str[i] - '0';
				}
				if (sum)
				{
					s += str;
					str = "";
				}
				else
					str = "";
			}
			if (s.length() == 56)
			{
				ans = solve(s);
				break;
			}
		}
		temp++;
	}
	return ans;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		memset(code, 0, sizeof(code));
		cin >> N >> M;
		vector<int> v;
		for (int i = 0; i < N; ++i)
		{
			string str;
			cin >> str;
			if (oneToken(i, str))
				v.push_back(i);
		}
		if (M < 56)
		{
			cout << '#' << cases << ' ' << 0 << '\n';
			continue;
		}
		int ans = check(v[0]);
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}
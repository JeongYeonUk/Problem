#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000;
const int MAX_N = 5001;

char arr[MAX_N];
int d[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> arr;

	int len = 0;
	for (int i = 0; arr[i] != '\0'; ++i)
	{
		len++;
	}

	if (len == 1 && arr[0] == '0')
		cout << "0\n";
	else
	{
		d[0] = 1;
		for (int i = 1; i <= len; ++i)
		{
			if (arr[i-1] - '0' >= 1 && arr[i-1] - '0' <= 9)
			{
				d[i] = (d[i - 1] + d[i]) % MOD;
			}
			if (i == 1)
				continue;
			int tmp = (arr[i-1] - '0') + (arr[i - 2] - '0') * 10;
			if (10 <= tmp && tmp <= 26)
			{
				d[i] = (d[i - 2] + d[i]) % MOD;
			}
		}
		cout << d[len] << '\n';
	}

	return 0;
}

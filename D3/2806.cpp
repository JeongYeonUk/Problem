#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 11;

int N;
int col[MAX];
int result;

bool promising(int i)
{
	for (int j = 0; j < i; ++j)
	{
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
			return false;
	}
	return true;
}

void N_Queen(int i)
{
	if (i == N)
		result += 1;
	else
	{
		for (int j = 0; j < N; ++j)
		{
			col[i] = j;
			if (promising(i))
				N_Queen(i + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		result = 0;
		cin >> N;
		N_Queen(0);
		cout << '#' << cases << ' ' << result << '\n';
	}

	return 0;
}
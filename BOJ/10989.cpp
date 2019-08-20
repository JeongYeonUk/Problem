#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 10001;

int arr[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int tmp; cin >> tmp;
		arr[tmp] += 1;
	}
	for (int i = 1; i <= 10000; ++i)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; ++j)
			{
				cout << i << '\n';
			}
		}
	}

	return 0;
}

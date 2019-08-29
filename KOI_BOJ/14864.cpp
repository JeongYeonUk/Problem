#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX_N = 100001;
int arr[MAX_N];
bool visit[MAX_N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		arr[i] = i;
	}
	for (int i = 0; i < M; ++i)
	{
		int x, y; cin >> x >> y;
		arr[x]++;
		arr[y]--;
	}
	bool fail = false;
	for (int i = 1; i <= N; ++i)
	{
		if (visit[arr[i]])
		{
			fail = true;
			break;
		}
		else
			visit[arr[i]] = true;
	}
	if (fail)
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			cout << arr[i] << ' ';
		}
	}

	return 0;
}
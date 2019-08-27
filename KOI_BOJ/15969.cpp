#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	sort(arr + 1, arr + N + 1);

	cout << arr[N] - arr[1] << '\n';

	return 0;
}
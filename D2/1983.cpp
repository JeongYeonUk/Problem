#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

pair<int, int> arr[MAX];

bool compare(pair<int, int>a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int N, K; cin >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			int a, b, c; cin >> a >> b >> c;
			a *= 0.35; b *= 0.45; c *= 0.20;
			arr[i].first = (a + b + c);
			if (i == (K - 1))
				arr[i].second = 1;
			else
				arr[i].second = 0;
		}
		sort(arr, arr + N, compare);
		int index = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i].second == 1)
			{
				index = i;
				break;
			}
		}
		int ans = index / (N / 10);
		switch (ans)
		{
		case 0:
			cout << '#' << cases << ' ' << "A+" << '\n';
			break;
		case 1:
			cout << '#' << cases << ' ' << "A0" << '\n';
			break;
		case 2:
			cout << '#' << cases << ' ' << "A-" << '\n';
			break;
		case 3:
			cout << '#' << cases << ' ' << "B+" << '\n';
			break;
		case 4:
			cout << '#' << cases << ' ' << "B0" << '\n';
			break;
		case 5:
			cout << '#' << cases << ' ' << "B-" << '\n';
			break;
		case 6:
			cout << '#' << cases << ' ' << "C+" << '\n';
			break;
		case 7:
			cout << '#' << cases << ' ' << "C0" << '\n';
			break;
		case 8:
			cout << '#' << cases << ' ' << "C-" << '\n';
			break;
		case 9:
			cout << '#' << cases << ' ' << "D0" << '\n';
			break;
		default:
			break;
		}
	}

	return 0;
}
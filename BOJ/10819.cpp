#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int solve(const vector<int>& vec)
{
	int size = vec.size();
	int i = 0, j = 1;
	int sum = 0;
	while (j != size)
	{
		sum += abs(vec[i] - vec[j]);
		i++; j++;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	vector<int> vec;
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int tmp; cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	int iMax = 0;
	do {
		iMax = max(iMax, solve(vec));
	} while (next_permutation(vec.begin(), vec.end()));

	cout << iMax << '\n';
	return 0;
}

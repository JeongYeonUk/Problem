#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	for (int i = 0; i < (int)arr1.size(); ++i) {
		for (int j = 0; j < (int)arr1[i].size(); ++j) {
			arr1[i][j] += arr2[i][j];
		}
	}
	return arr1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<vector<int>> ret = solution({ {1,2},{2,3} }, { {3,4},{5,6} });

	return 0;
}

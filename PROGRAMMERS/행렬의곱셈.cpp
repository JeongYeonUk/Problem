#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
	vector<vector<int>> answer;

	int m = (int)arr1.size();
	int n = (int)arr2[0].size();
	int p = (int)arr1[0].size();

	for (int i = 0; i < m; ++i) {
		vector<int> row;
		for (int j = 0; j < n; ++j) {
			int tmp = 0;
			for (int k = 0; k < p; ++k) {
				tmp += arr1[i][k] * arr2[k][j];
			}
			row.push_back(tmp);
		}
		answer.push_back(row);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<vector<int>> answer = solution({ {2,3,2},{4,2,4},{3,1,4} }, { {5,4,3},{2,4,1},{3,1,1} });

	for (auto a : answer) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(vector<vector<string>> clothes) 
{
	int answer = 1;
	map<string, int> m;
	for (int i = 0; i < (int)clothes.size(); ++i)
	{
		m[clothes[i][1]] += 1;
	}
	for (auto elem : m)
	{
		answer *= elem.second + 1;
	}
	return answer - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution({
		{"yellow_hat", "headgear"}
	, {"blue_sunglasses", "eyewear"}
	, {"green_turban","headgear"} }) << endl;

	return 0;
}

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

int solution(vector<int> people, int limit) 
{
	int answer = 0;
	sort(people.begin(), people.end());
	vector<int> ret;
	ret.assign(people.size(), 0);
	int len = (int)people.size();
	int light = 0, heavy = len - 1;
	int cnt = 0;
	while (light < heavy)
	{
		if (people[light] + people[heavy] <= limit)
		{
			cnt += 1;
			light += 1;
			heavy -= 1;
		}
		else
			heavy -= 1;
	}
	answer = len - cnt;
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution({70,80,50},100) << endl;

	return 0;
}

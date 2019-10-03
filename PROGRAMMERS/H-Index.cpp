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

int solution(vector<int> citations) 
{
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int i = 0; i <= (int)citations.size(); ++i)
	{
		int h = i;
		int cnt = 0;
		for (int j = 0; j < (int)citations.size(); ++j)
		{
			if(h <= citations[j])
				cnt++;
		}
		if (h <= cnt)
			answer = max(answer,h);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cout << solution({22,42}) << endl;

	return 0;
}

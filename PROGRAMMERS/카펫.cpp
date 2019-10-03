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

vector<int> solution(int brown, int red) 
{
	vector<int> answer;
	int sum = brown + red;
	int limit = (int)sqrt(sum);
	for (int i = 3; i <= limit; ++i)
	{
		if (sum % i == 0)
		{
			int tmp = sum / i;
			if ((tmp - 2) * (i - 2) == red)
			{
				answer.push_back(tmp);
				answer.push_back(i);
				break;
			}
		}
	}
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<int> ret = solution(24,24);
	for (auto elem : ret)
	{
		cout << elem << ' ';
	}
	return 0;
}

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
	// w * h = brown + red
	// (w - 2) * (h - 2) = red
	// 두 식을 연립방정식으로
	// w + h = brown / 2 + 2;

	int len = (brown >> 1) + 2;

	int w = len - 3;
	int h = 3;

	while (w >= h) {
		if (w * h == (brown + red)) break;
		w--;
		h++;
	}

	return vector<int>(w, h);
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

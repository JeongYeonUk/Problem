#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 500003;

struct Person
{
	int score[4];
};

bool cmp(Person& a, Person& b)
{
	return a.score[1] < b.score[1];
}

Person person[MAX_N];
int tree[MAX_N * 4];
int N;

int update(int node, int left, int right, int idx, int val)
{
	if (idx < left || right < idx)
		return tree[node];
	if (left == right)
		return tree[node] = val;
	int mid = (left + right) >> 1;
	return tree[node] = min(update(node * 2, left, mid, idx, val)
		, update(node * 2 + 1, mid + 1, right, idx, val));
}

int query(int node, int left, int right, int qleft, int qright)
{
	if (qright < left || right < qleft)
		return INF;
	if (qleft <= left && right <= qright)
		return tree[node];
	int mid = (left + right) >> 1;
	return min(query(node * 2, left, mid, qleft, qright),
		query(node * 2 + 1, mid + 1, right, qleft, qright));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int tmp; cin >> tmp;
			person[tmp].score[i] = j;
		}
	}

	sort(person + 1, person + N + 1, cmp);
	for (int i = 1; i <= N; ++i)
	{
		update(1, 1, N, i, INF);
	}
	int ret = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (query(1, 1, N, 1, person[i].score[2]) > person[i].score[3])
			ret++;
		update(1, 1, N, person[i].score[2], person[i].score[3]);
	}
	cout << ret << '\n';
	return 0;
}

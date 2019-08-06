#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 100001;
const int MAX_K = 50001;
int N, K;
int arr[MAX_N];
struct Segment
{
	vector<int> Max, Min;
	int size;
	Segment(int n) : size(n)
	{
		Max.resize(4 * size, 0);
		Min.resize(4 * size, INF);
	}
	void init(int node, int left, int right)
	{
		if (left == right)
		{
			Max[node] = Min[node] = left;
			return;
		}
		int mid = (left + right) >> 1;
		init(node * 2, left, mid);
		init(node * 2 + 1, mid + 1, right);
		Min[node] = min(Min[node * 2], Min[node * 2 + 1]);
		Max[node] = max(Max[node * 2], Max[node * 2 + 1]);
	}
	void init()
	{
		init(1, 0, size - 1);
	}
	void update(int node, int left, int right, int idx, int value)
	{
		if (idx < left || right < idx)
			return;
		if (left == right)
		{
			Min[node] = Max[node] = value;
			return;
		}
		int mid = (left + right) >> 1;
		update(node * 2, left, mid, idx, value);
		update(node * 2 + 1, mid + 1, right, idx, value);
		Min[node] = min(Min[node * 2], Min[node * 2 + 1]);
		Max[node] = max(Max[node * 2], Max[node * 2 + 1]);
	}
	void update(int val, int idx)
	{
		update(1, 0, size - 1, idx, val);
	}
	pii query(int node, int left, int right, int qleft, int qright)
	{
		if (qright < left || right < qleft)
			return { INF,0 };
		if (qleft <= left && right <= qright)
			return { Min[node], Max[node] };
		int mid = (left + right) >> 1;
		pii f = query(node * 2, left, mid, qleft, qright);
		pii s = query(node * 2 + 1, mid + 1, right, qleft, qright);
		return { min(f.first,s.first), max(f.second, s.second) };
	}
	pii query(int left, int right)
	{
		return query(1, 0, size - 1, left, right);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		memset(arr, 0, sizeof(arr));
		cin >> N >> K;
		for (int i = 1; i <= N; ++i)
		{
			arr[i] = i;
		}
		Segment seg(N);
		seg.init();
		for (int i = 1; i <= K; ++i)
		{
			int Q; cin >> Q;
			if (Q == 0)
			{
				int A, B; cin >> A >> B;
				pii a = seg.query(A, A);
				pii b = seg.query(B, B);
				seg.update(b.first, A);
				seg.update(a.first, B);
			}
			else if (Q == 1)
			{
				int A, B; cin >> A >> B;
				pii get = seg.query(A, B);
				if (get.first == A && get.second == B)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}

	return 0;
}

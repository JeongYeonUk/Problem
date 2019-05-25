#include <iostream>
#include <vector>
using namespace std;

int cal(const vector<int>& s, const vector<int>& l)
{
	int count = l.size() - s.size() + 1;
	int max = 0;
	for (int i = 0; i < count; ++i)
	{
		int index = i;
		int ans = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			ans += s[i] * l[index];
			index++;
		}
		if (max < ans)
			max = ans;
	}
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int N, M; cin >> N >> M;
		vector<int> A(N);
		vector<int> B(M);
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
		}
		for (int i = 0; i < M; ++i)
		{
			cin >> B[i];
		}

		int ans = 0;
		if (A.size() < B.size())
			ans = cal(A, B);
		else
			ans = cal(B, A);

		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}
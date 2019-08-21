#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int E, S, M; cin >> E >> S >> M;
	int e, s, m,ret; ret = e = s = m = 1;
	
	while (true)
	{		
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
		if (e == E && s == S && m == M)
			break;
		e++; s++; m++; ret++;
	}
	cout << ret << '\n';
	return 0;
}

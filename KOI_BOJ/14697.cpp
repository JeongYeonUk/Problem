#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

// 방 정원 기준으로 3종류의 방
// 같은 종류의 방들이 여러개
// 빈 침대 x


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, C, N; cin >> A >> B >> C >> N;
	int tmp1, tmp2, tmp3;
	for (int i = 0; i <= 300; ++i)
	{
		tmp1 = A * i;
		for (int j = 0; j <= 300; ++j)
		{
			tmp2 = B * j;
			for (int k = 0; k <= 300; ++k)
			{
				tmp3 = C * k;
				if (tmp1 + tmp2 + tmp3 == N)
				{
					cout << "1\n";
					return 0;
				}
			}
		}
	}
	cout << "0\n";
	return 0;
}
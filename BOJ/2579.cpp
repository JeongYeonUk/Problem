#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 300 + 1;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int a[MAX];
int d[MAX];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
	}

	// �ִ밪�� ��� ���̹Ƿ�
	// 2���� ��ܱ�����
	// ��� ����� ��� ���� �ִ밪
	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= N; ++i)
	{
		// 3���� ����� �������� ���� ���ϹǷ�
		d[i] = a[i] + a[i - 1] + d[i - 3];

		// ���� ����� ���� ���� ���
		d[i] = max(d[i], a[i] + d[i - 2]);
	}

	cout << d[N] << endl;

	return 0;
}

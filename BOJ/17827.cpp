#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxN = 200000 + 1;

int arr[maxN];
vector<int> vec;
int N, M, V;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M >> V;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (i >= (V - 1)) vec.push_back(arr[i]);
	}

	int size = (int)vec.size();
	int num;
	for (int i = 0; i < M; ++i)
	{
		cin >> num;
		if (num < N) {
			cout << arr[num] << endl; 
			continue;
		}
		cout << vec[(num - N) % size] << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 101;
int N;

vector<int> slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	const int N = preorder.size();
	if (preorder.empty())
		return;
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - L - 1;

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout << root << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		int N; cin >> N;
		vector<int> preorder, inorder;
		for (int i = 0; i < N; ++i)
		{
			int node; cin >> node;
			preorder.push_back(node);
		}
		for (int i = 0; i < N; ++i)
		{
			int node; cin >> node;
			inorder.push_back(node);
		}
		printPostOrder(preorder, inorder);
		cout << '\n';
	}

	return 0;
}

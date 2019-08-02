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

struct TreeNode
{
	vector<TreeNode*> children;
};

int N, y[MAX_N], x[MAX_N], radius[MAX_N];
int longest;

int height(TreeNode* root)
{
	vector<int> heights;
	for (int i = 0; i < root->children.size(); ++i)
		heights.push_back(height(root->children[i]));
	if (heights.empty())
		return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2]
			+ heights[heights.size() - 1]);
	return heights.back() + 1;
}

int solve(TreeNode* root)
{
	longest = 0;
	int h = height(root);
	return max(longest, h);
}

int sqr(int x)
{
	return x * x;
}

int sqrdist(int a, int b)
{
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b)
{
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child)
{
	if (!encloses(parent, child))
		return false;
	for (int i = 0; i < N; ++i)
	{
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
			return false;
	}
	return true;
}

TreeNode* getTree(int root)
{
	TreeNode* result = new TreeNode();
	for (int ch = 0; ch < N; ++ch)
	{
		if (isChild(root, ch))
			result->children.push_back(getTree(ch));
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> x[i] >> y[i] >> radius[i];			
		}
		TreeNode* T = getTree(0);
		cout << solve(T) << '\n';
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 50001;

struct Node
{
	int key;
	int priority;
	int size;
	Node* left, * right;
	Node(const int& _key) 
		: key(_key)
		, priority(rand())
		, size(1)
		, left(nullptr)
		, right(nullptr)
	{}
	void setLeft(Node* newLeft)
	{
		left = newLeft;
		calcSize();
	}
	void setRight(Node* newRight)
	{
		right = newRight;
		calcSize();
	}
	void calcSize()
	{
		size = 1;
		if (left)
			size += left->size;
		if (right)
			size += right->size;
	}
};

typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root, int key)
{
	if (root == nullptr)
		return NodePair(nullptr, nullptr);
	if (root->key < key)
	{
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node)
{
	if (root == nullptr)
		return node;
	if (root->priority < node->priority)
	{
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

Node* merge(Node* a, Node* b)
{
	if (a == nullptr)
		return b;
	if (b == nullptr)
		return a;
	if (a->priority < b->priority)
	{
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

Node* erase(Node* root, int key)
{
	if (root == nullptr)
		return root;
	if (root->key == key)
	{
		Node* result = merge(root->left, root->right);
		delete root;
		return result;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));

	return root;
}

Node* kth(Node* root, int k)
{
	int leftSize = 0;
	if (root->left != nullptr)
		leftSize = root->left->size;
	if (k <= leftSize)
		return kth(root->left, k);
	if (k == leftSize + 1)
		return root;
	return kth(root->right, k - leftSize - 1);
}

int countLessThan(Node* root, int key)
{
	if (root == nullptr)
		return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}

int N;
int shifted[MAX_N];
int A[MAX_N];

void solve()
{
	Node* candidates = nullptr;
	for (int i = 0; i < N; ++i)
		candidates = insert(candidates, new Node(i + 1));
	for (int i = N - 1; i >= 0; --i)
	{
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		A[i] = k->key;
		candidates = erase(candidates, k->key);
	}
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
			cin >> shifted[i];
		solve();
		for (int i = 0; i < N; ++i)
			cout << A[i] << ' ';
		cout << '\n';
	}

	return 0;
}

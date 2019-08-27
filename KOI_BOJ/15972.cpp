#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 987654321;

struct hole
{
	int up, down, left, right;
};
struct pqelem
{
	int x, y, amount;
};

struct cmp
{
	bool operator()(pqelem& a, pqelem& b)
	{
		return a.amount > b.amount ? true : false;
	}
};

vector<vector<hole> >input;
vector<vector<int> > ans;
priority_queue<pqelem, vector<pqelem>, cmp>pq;
int n, m, h;
int sum;

int fi(int k)
{
	return (k >= 0) ? k : h;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int temp;
	cin >> n >> m >> h;
	input.resize(n + 1, vector<hole>(m + 1, { -1,-1,-1,-1 }));
	ans.resize(n + 1, vector<int>(m + 1, h));

	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		input[0][i].up = temp;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			input[i][j].down = temp;
			input[i + 1][j].up = temp;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		input[n - 1][i].down = temp;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		input[i][0].left = temp;
		for (int j = 0; j < m - 1; ++j)
		{
			cin >> temp;
			input[i][j].right = temp;
			input[i][j + 1].left = temp;
		}
		cin >> temp;
		input[i][m - 1].right = temp;
	}

	if (n == 1 && m == 1)
	{
		cout << min(fi(input[0][0].up),
			min(fi(input[0][0].down),
				min(fi(input[0][0].left),
					fi(input[0][0].right)))) << '\n';
		return 0;
	}
	else if (n == 1)
	{
		ans[0][0] = min({ fi(input[0][0].up)
			, fi(input[0][0].left)
			, fi(input[0][0].down) });
		ans[0][m-1] = min({ fi(input[0][m - 1].up)
			, fi(input[0][m - 1].right)
			, fi(input[0][m - 1].down) });
		pq.push({ 0,0,ans[0][0] });
		pq.push({ 0,m - 1,ans[0][m - 1] });
	}
	else if (m == 1)
	{
		ans[0][0] = min({ fi(input[0][0].right)
			, fi(input[0][0].left)
			, fi(input[0][0].up) });
		ans[n-1][0] = min({ fi(input[n-1][0].left)
			, fi(input[n-1][0].right)
			, fi(input[n-1][0].down) });
		pq.push({ 0,0,ans[0][0] });
		pq.push({ n - 1,0,ans[n - 1][0] });
	}
	else
	{
		ans[0][0] = min(fi(input[0][0].up), fi(input[0][0].left));
		ans[0][m - 1] = min(fi(input[0][m-1].up), fi(input[0][m - 1].right));
		ans[n - 1][0] = min(fi(input[n - 1][0].left), fi(input[n - 1][0].down));
		ans[n - 1][m - 1] = min(fi(input[n - 1][m - 1].right), fi(input[n - 1][m - 1].down));

		pq.push({ 0,0,ans[0][0] });
		pq.push({ 0,m-1,ans[0][m-1] });
		pq.push({ n-1,0,ans[n-1][0] });
		pq.push({ n-1,m-1,ans[n-1][m-1] });
	}

	for (int i = 1; i < n - 1; ++i)
	{
		if (m == 1)
		{
			ans[i][0] = min(fi(input[i][0].left), fi(input[i][0].right));
			pq.push({ i,0,ans[i][0] });
		}
		else
		{
			ans[i][0] = fi(input[i][0].left);
			ans[i][m - 1] = fi(input[i][m - 1].right);

			pq.push({ i,0,ans[i][0] });
			pq.push({ i,m - 1,ans[i][m - 1] });
		}
	}

	while (!pq.empty())
	{
		int x = pq.top().x, y = pq.top().y, amount = pq.top().amount;
		cout << x << ' ' << y << ' ' << amount << '\n';
		pq.pop();
		if (ans[x][y] != amount)
			continue;
		if (x > 0
			&& input[x][y].up >= 0
			&& ans[x - 1][y] > input[x][y].up
			&& ans[x][y] <= input[x][y].up)
		{
			ans[x - 1][y] = input[x][y].up;
			pq.push({ x - 1,y,ans[x - 1][y] });
		}
		else if (x > 0
			&& input[x][y].up >= 0
			&& ans[x][y] >= input[x][y].up
			&& ans[x - 1][y] > ans[x][y])
		{
			ans[x - 1][y] = ans[x][y];
			pq.push({ x - 1,y,ans[x - 1][y] });
		}

		if (x < n - 1
			&& input[x][y].down >= 0
			&& ans[x + 1][y] > input[x][y].down
			&& ans[x][y] <= input[x][y].down)
		{
			ans[x + 1][y] = input[x][y].down;
			pq.push({ x + 1,y,ans[x + 1][y] });
		}
		else if (x < n - 1
			&& input[x][y].down >= 0
			&& ans[x][y] >= input[x][y].down
			&& ans[x][y] < ans[x+1][y])
		{
			ans[x + 1][y] = ans[x][y];
			pq.push({ x + 1,y,ans[x + 1][y] });
		}

		if (y > 0
			&& input[x][y].left >= 0
			&& ans[x][y - 1] > input[x][y].left
			&& ans[x][y] <= input[x][y].left)
		{
			ans[x][y - 1] = input[x][y].left;
			pq.push({ x,y - 1, ans[x][y - 1] });
		}
		else if (y > 0
			&& input[x][y].left >= 0
			&& ans[x][y] >= input[x][y].left
			&& ans[x][y-1] > ans[x][y])
		{
			ans[x][y - 1] = ans[x][y];
			pq.push({ x,y - 1, ans[x][y - 1] });
		}

		if (y < m - 1
			&& input[x][y].right >= 0
			&& ans[x][y + 1] > input[x][y].right
			&& ans[x][y] <= input[x][y].right)
		{
			ans[x][y + 1] = input[x][y].right;
			pq.push({ x,y + 1,ans[x][y + 1] });
		}
		else if (y < m - 1
			&& input[x][y].right >= 0
			&& ans[x][y] >= input[x][y].right
			&& ans[x][y+1] > ans[x][y])
		{
			ans[x][y + 1] = ans[x][y];
			pq.push({ x,y + 1,ans[x][y + 1] });
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			sum += ans[i][j];
		}
	}
	cout << sum << '\n';

	return 0;
}
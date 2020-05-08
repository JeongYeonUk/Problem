#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	stack<int> s;

	for (int move = 0, m_size = (int)moves.size(); move < m_size; ++move)
	{
		int x = moves[move] - 1;

		for (int y = 0, b_size = (int)board.size(); y < b_size; ++y)
		{
			if (board[y][x])
			{
				if (s.empty())
					s.push(board[y][x]);
				else if (s.top() == board[y][x])
				{
					answer += 2;
					s.pop();
				}
				else
					s.push(board[y][x]);
				board[y][x] = 0;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	vector<vector<int>> board =
	{
		{0,0,0,0,0},
		{0,0,1,0,3},
		{0,2,5,0,1},
		{4,2,4,4,2},
		{3,5,1,3,1}
	};

	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves) << endl;

	return 0;
}

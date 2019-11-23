#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int operands[10];
char operators[10];
int n, operandsCnt, operatorsCnt;
ll answer;

ll calc(ll a, ll b, char op)
{
	ll ret = 0;
	switch (op)
	{
	case '+':
		ret = a + b;
		break;
	case '-':
		ret = a - b;
		break;
	case '*':
		ret = a * b;
		break;
	default:
		break;
	}
	return ret;
}

void dfs(ll ret, int operatorIdx)
{
	ll nextRet = 0, nowRet = 0;
	if (operatorIdx >= operatorsCnt) 
	{
		if (answer < ret)
			answer = ret;
		return;
	}
	nowRet = calc(ret, operands[operatorIdx + 1], operators[operatorIdx]);
	dfs(nowRet, operatorIdx + 1);

	if (operatorIdx + 2 < operandsCnt)
	{
		nextRet = calc(operands[operatorIdx + 1], operands[operatorIdx + 2], operators[operatorIdx + 1]);
		nowRet = calc(ret, nextRet, operators[operatorIdx]);
		dfs(nowRet, operatorIdx + 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		if (i & 1)
			cin >> operators[operatorsCnt++];
		else
			cin >> operands[operandsCnt++];
	}
	answer = -INF;
	dfs(operands[0], 0);
	cout << answer << endl;
	return 0;
}

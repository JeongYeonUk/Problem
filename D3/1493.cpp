#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CPoint
{
	friend int operatorSharp(const CPoint& p);
private:
	int mX; int mY;
public:
	CPoint(int x = 0, int y = 0)
		: mX(x), mY(y)
	{}

	CPoint operator+(const CPoint& rhs)
	{
		mX += rhs.mX;
		mY += rhs.mY;
		return *this;
	}
};

CPoint operatorAmp(int p)
{
	int n = 1;
	while (1)
	{
		if ((1 + n * (n - 1) / 2) <= p && p < (1 + (n + 1) * n / 2))
			break;
		n++;
	}
	int x = 1, y = n;
	int offset = p - (1 + n * (n - 1) / 2);
	x += offset;
	y -= offset;
	return CPoint(x, y);
}

int operatorSharp(const CPoint& p)
{
	CPoint temp = p;
	int offset = temp.mX - 1;
	temp.mX -= offset;
	temp.mY += offset;

	int n = temp.mY;
	int an = 1 + n * (n - 1) / 2;

	return an + offset;
}

int operatorStar(int p, int q)
{
	CPoint pointP = operatorAmp(p), pointQ = operatorAmp(q);
	return operatorSharp(pointP + pointQ);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int p, q; cin >> p >> q;
		cout << '#' << cases << ' ' << operatorStar(p, q) << '\n';
	}

	return 0;
}
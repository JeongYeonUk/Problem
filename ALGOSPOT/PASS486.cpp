#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

inline int MIN(int a, int b)
{
	return a > b ? b : a;
}

const int INF = 10000000;
int minFactor[INF + 1];
int minFactorPower[INF + 1];
int factors[INF + 1];

void era()
{
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i <= INF; ++i)
	{
		minFactor[i] = i;
	}
	int sqrtN = int(sqrt(INF));
	for (int i = 2; i <= sqrtN; ++i)
	{
		if (minFactor[i] == i)
		{
			for (int j = i * i; j <= INF; j+=i)
			{
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}

void getFactor()
{
	factors[1] = 1;
	for (int i = 2; i <= INF; ++i)
	{
		if (minFactor[i] == i)
		{
			minFactorPower[i] = 1;
			factors[i] = 2;
		}
		else
		{
			int prime = minFactor[i];
			int divisor = i / prime;
			if (prime != minFactor[divisor])
				minFactorPower[i] = 1;
			else
				minFactorPower[i] = minFactorPower[divisor] + 1;
			int exponent = minFactorPower[i];
			factors[i] = (factors[divisor] / exponent) *
				(exponent + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	era();
	getFactor();
	for (int cases = 0; cases < T; ++cases)
	{
		int divisorNum, low, high;
		cin >> divisorNum >> low >> high;
		int result = 0;
		for (int i = low; i <= high; ++i)
		{
			if (factors[i] == divisorNum)
				result++;
		}
		cout << result << '\n';
	}

	return 0;
}

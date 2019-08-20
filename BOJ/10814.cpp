#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 100001;

struct p
{
	int old;
	char name[101];
	int len;
	int number;
};

p arr[MAX_N];

void strswap(char* a, char* b, int alen, int blen)
{
	char* tmp = (char*)malloc(sizeof(char) * 101);
	for (int i = 0; a[i] != '\0'; ++i)
	{
		tmp[i] = a[i];
	}
	tmp[alen] = '\0';
	memset(a, 0, sizeof(a));
	for (int i = 0; b[i] != '\0'; ++i)
	{
		a[i] = b[i];
	}
	a[blen] = '\0';
	memset(b, 0, sizeof(b));
	for (int i = 0; tmp[i] != '\0'; ++i)
	{
		b[i] = tmp[i];
	}
	b[alen] = '\0';
	free(tmp);
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void pswap(p& a, p& b)
{
	swap(a.old, b.old);
	swap(a.number, b.number);
	strswap(a.name, b.name, a.len, b.len);
	swap(a.len, b.len);
}

void quicksort(int start, int end)
{
	int pivot = start;
	int i, j = start;
	if (start < end)
	{
		for (i = start + 1; i <= end; ++i)
		{
			if (arr[i].old < arr[pivot].old)
			{
				j++;
				pswap(arr[i], arr[j]);
			}
			else if (arr[i].old == arr[pivot].old)
			{
				if (arr[i].number < arr[pivot].number)
				{
					j++;
					pswap(arr[i], arr[j]);
				}
			}
		}
		pswap(arr[pivot], arr[j]);
		pivot = j;
		quicksort(start, pivot - 1);
		quicksort(pivot + 1, end);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].old >> arr[i].name;
		arr[i].number = i;
	}
	for (int i = 1; i <= N; ++i)
	{
		int len = 0;
		for (int j = 0; arr[i].name[j] != '\0'; ++j)
		{
			len++;
		}
		arr[i].len = len;
	}

	quicksort(1, N);

	for (int i = 1; i <= N; ++i)
	{
		cout << arr[i].old << ' ' << arr[i].name << '\n';
	}

	return 0;
}

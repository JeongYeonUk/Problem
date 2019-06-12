#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int N;
int graph[100][100];

void floyd()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				if (graph[j][i] && graph[i][k])
					graph[j][k] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	floyd();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	return 0;
}

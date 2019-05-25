#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

using Point = pair<int, int>;

int map[50][50];
int visit[50][50];
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int N, M, R, C, L;
int ans;

void bfs()
{
	visit[R][C] = 1;
	queue<Point> q;
	q.push({ R,C });
	while (L--)
	{
		int size = (int)q.size();
		for (int k = 0; k < size; ++k)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			ans++;
			for (int i = 1; i <= 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int prev = map[x][y];
				if (0 <= nx && nx < N && 0 <= ny && ny < M)
				{
					if (visit[nx][ny]) continue;
					if (!map[nx][ny]) continue;
					int next = map[nx][ny];
					switch (prev)
					{
					case 1:
					{
						switch (i)
						{
						case 1:
						{
							if (next == 1 || next == 2 || next == 5 || next == 6)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 2:
						{
							if (next == 1 || next == 2 || next == 4 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 3:
						{
							if (next == 1 || next == 3 || next == 4 || next == 5)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 4:
						{
							if (next == 1 || next == 3 || next == 6 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						default:
							break;
						}
						break;
					}
					case 2:
					{
						switch (i)
						{
						case 1:
						{
							if (next == 1 || next == 2 || next == 5 || next == 6)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 2:
						{
							if (next == 1 || next == 2 || next == 4 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						default:
							break;
						}
						break;
					}
					case 3:
					{
						switch (i)
						{
						case 3:
						{
							if (next == 1 || next == 3 || next == 4 || next == 5)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 4:
						{
							if (next == 1 || next == 3 || next == 6 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						default:
							break;
						}
						break;
					}
					case 4:
					{
						switch (i)
						{
						case 1:
						{
							if (next == 1 || next == 2 || next == 5 || next == 6)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 4:
						{
							if (next == 1 || next == 3 || next == 6 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						default:
							break;
						}
						break;
					}
					case 5:
					{
						switch (i)
						{
						case 2:
						{
							if (next == 1 || next == 2 || next == 4 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 4:
						{
							if (next == 1 || next == 3 || next == 6 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						default:
							break;
						}
						break;
					}
					case 6:
					{
						switch (i)
						{
						case 2:
						{
							if (next == 1 || next == 2 || next == 4 || next == 7)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 3:
						{
							if (next == 1 || next == 3 || next == 4 || next == 5)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						default:
							break;
						}
						break;
					}
					case 7:
					{
						switch (i)
						{
						case 1:
						{
							if (next == 1 || next == 2 || next == 5 || next == 6)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						case 3:
						{
							if (next == 1 || next == 3 || next == 4 || next == 5)
							{
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								break;
							}
							else
								break;
						}
						default:
							break;
						}
						break;
					}
					default:
						break;
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		ans = 0;
		memset(visit, 0, sizeof(visit));
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> map[i][j];
			}
		}
		bfs();

		cout << '#' << cases << ' ' << ans << '\n';
	}
	return 0;
}
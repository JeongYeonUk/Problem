#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'
#define Y first
#define X second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int bfs(int sy, int sx, int m, int n, vector<vector<int>>& visited, const vector<vector<int>>& picture, int value) {
    visited[sy][sx] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));

    int candi = 1;

    while (!q.empty()) {
        int y = q.front().Y; int x = q.front().X;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
            if (value != picture[ny][nx]) continue;

            visited[ny][nx] = 1;
            candi++;
            q.push(make_pair(ny, nx));
        }
    }

    return candi;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<int> sector;

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            if (picture[y][x] && visited[y][x] == 0) {

            number_of_area++;
            int candi = bfs(y, x, m, n, visited, picture, picture[y][x]);
            sector.push_back(candi);
            }
        }
    }

    sort(sector.begin(), sector.end());
    max_size_of_one_area = sector.back();

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    vector<int> answer = solution(6, 4, { {1,1,1,0},{1,1,1,0},{0,0,0,1}, {0,0,0,1}, {0,0,0,1}, {0,0,0,1} });

    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}

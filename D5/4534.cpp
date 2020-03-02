#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100000 + 5;
const int MOD = 1000000007;

enum STATE {
    BLACK,
    WHITE
};

ll dp[MAX][2];
vector<int> adj[MAX];
int visit[MAX];

void init() {
    for (int i = 0; i < MAX; ++i) {
        adj[i].clear();
    }
    memset(visit, 0, sizeof(visit));
    memset(dp, -1, sizeof(dp));
}

ll solve(int cur, int color) {
    ll& ret = dp[cur][color];
    if (ret != -1)
        return ret;

    visit[cur] = true;
    ret = 1;
    for (int i = 0; i < (int)adj[cur].size(); ++i) {
        int next = adj[cur][i];
        if (visit[next])
            continue;

        ll temp = 0;
        if (color == BLACK) {
            temp = solve(next, WHITE) % MOD;
        }
        else {
            temp = (solve(next, WHITE) % MOD + solve(next, BLACK) % MOD) % MOD;
        }

        ret = (ret * temp) % MOD;
    }
    visit[cur] = false;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        init();
        int n; cin >> n;
        for (int i = 0; i < n - 1; ++i) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << '#' << t << ' ' << ((solve(1, BLACK) + solve(1, WHITE)) % MOD) << endl;
    }

    return 0;
}
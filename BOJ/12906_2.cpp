#pragma warning (disable : 4996)
#include <stdio.h>
#include <queue>
using namespace std;
int sum = 0;
int arr[3][11];
int idx[3];
int ans[3];
int res = 0;
bool visit[1 << 24];
int gethash() {
    int ret = 0;
    int t = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < idx[i]; j++) {
            ret += t * arr[i][j];
            t *= 4;
        }
        if (i < 2) ret += t * 3;
        t *= 4;
    }
    return ret;
}
void setarr(int h) {
    for (int i = 0; i < 3; i++)
        idx[i] = 0;
    int index = 0;
    for (int i = 0; i < sum + 2; i++) {
        if (h % 4 == 3)
            index++;
        else {
            arr[index][idx[index]] = h % 4;
            idx[index]++;
        }
        h /= 4;
    }
}
int bfs(int vis) {
    queue<int> q;
    int cnt = 0;
    q.push(vis);
    visit[vis] = true;
    while (++cnt) {
        int qsize = q.size();
        while (qsize--) {
            int x = q.front();
            q.pop();
            if (x == res)
                return cnt - 1;
            setarr(x);
            for (int i = 0; i < 3; i++) {
                if (!idx[i])
                    continue;
                for (int j = 0; j < 3; j++) {
                    if (i == j)
                        continue;
                    arr[j][idx[j]] = arr[i][idx[i] - 1];
                    idx[j]++; idx[i]--;
                    int vis = gethash();
                    if (!visit[vis]) {
                        visit[vis] = true;
                        q.push(vis);
                    }
                    idx[j]--; idx[i]++;
                }
            }
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    for (int i = 0; i < 3; i++) {
        scanf("%d", &idx[i]);
        if (!idx[i])
            continue;
        sum += idx[i];
        char c[11];
        scanf("%s", &c);
        for (int j = 0; j < idx[i]; j++) {
            arr[i][j] = c[j] - 'A'; ans[c[j] - 'A']++;
        }
    }
    int vis = gethash();
    int t = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < ans[i]; j++) {
            res += t * i;
            t *= 4;
        }
        if (i < 2) res += t * 3;
        t *= 4;
    }
    printf("%d\n", bfs(vis));
    return 0;
}
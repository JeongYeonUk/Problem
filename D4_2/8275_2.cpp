#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, X, M; //N:햄스터우리, X:우리당 최대마리수, M:기록 개수
int trr[12];
int prr[12];
int arr[12];
int vis[12];

struct Cond {
    int l;
    int r;
    int s;
};
Cond cond[100];

int ans;

bool check() {

    for (int i = 0; i < M; i++) {

        int sum = 0;
        for (int j = cond[i].l; j <= cond[i].r; j++) {
            sum += prr[j];
        }
        if (sum != cond[i].s) return false;
    }
    return true;
}

//메모장번호,햄스터우리,총햄스터
void dfs(int n, int p, int psum, int sum) {

    if (p == cond[n].r + 1) {

        if (psum != cond[n].s) return;
        if (n == M - 1) {

            if (check() && sum > ans) {

                ans = sum;
                for (int i = 1; i <= N; i++) arr[i] = prr[i];
            }
            return;
        }
        n++, p = cond[n].l;
        psum = 0;
        for (int i = cond[n].l; i <= cond[n].r; i++) if (prr[i] != -1) psum += prr[i];
        dfs(n, p, psum, sum);
    }

    if (prr[p] != -1) dfs(n, p + 1, psum, sum);
    else {
        for (int i = 0; i <= X; i++) {

            prr[p] = i;
            dfs(n, p + 1, psum + i, sum + i);
            prr[p] = -1;
        }
    }
}

int main(void) {
    int T;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int ab = 1; ab <= T; ab++) {

        ans = -1;
        scanf("%d%d%d", &N, &X, &M);
        for (int i = 1; i <= N; i++) trr[i] = 0, prr[i] = -1;

        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &cond[i].l, &cond[i].r, &cond[i].s);
            for (int j = cond[i].l; j <= cond[i].r; j++) trr[j] = 1;
        }
        dfs(0, cond[0].l, 0, 0);

        if (ans == -1) printf("#%d -1\n", ab);
        else {
            for (int i = 1; i <= N; i++) if (trr[i] == 0) arr[i] = X;

            printf("#%d ", ab);
            for (int i = 1; i <= N; i++) printf("%d ", arr[i]);
            printf("\n");
        }
    }
}
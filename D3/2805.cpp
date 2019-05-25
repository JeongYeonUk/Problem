#include <stdio.h>
int map[50][50];
int main(void) {
  int test_case;
  scanf("%d", &test_case);
  for (int z = 1; z <= test_case; z++) {
    int n;
    scanf("%d", &n);
    int i, j, k, l;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%1d", &map[i][j]);
      }
    }
    int sum = 0;
    int cnt = 1;
    j = n / 2;
    for (i = 0; i <= n / 2; i++, j--) {
      for (k = 1, l = j; k <= cnt; l++, k++) {
        sum += map[i][l];
      }
      cnt += 2;
    }
    cnt -= 4;
    j += 2;
    for (; i < n; i++, j++) {
      for (k = 1, l = j; k <= cnt; l++, k++) {
        sum += map[i][l];
      }
      cnt -= 2;
    }
    printf("#%d %d\n", z, sum);
  }
}

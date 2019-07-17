#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;

const int MAX = 1e5 + 1;

ll w[MAX];
int p[MAX];

int find(int x) {
  if (p[x] < 0)
    return x;
  int prev = find(p[x]);
  w[x] += w[p[x]];
  return p[x] = prev;
}

void union_set(int a, int b, int c) {
  int ta = a, tb = b;
  a = find(a), b = find(b);
  if (a == b) return;
  if (p[a] > p[b]) {
    swap(a, b);
    swap(ta, tb);
    c = -c;
  }
  p[a] += p[b];
  p[b] = a;
  w[b] += c - w[tb] + w[ta];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    fill(w, w + N + 1, 0);
    fill(p, p + N + 1, -1);
    for (int i = 0; i < M; i++) {
      char q;
      int a, b;
      cin >> q >> a >> b;
      if (q == '!') {
        int c;
        cin >> c;
        union_set(a, b, c);
      }
      else {
        if (find(a) != find(b))
          cout << "UNKNOWN\n";
        else
          cout << w[b] - w[a] << "\n";
      }
    }
  }
  return 0;
}

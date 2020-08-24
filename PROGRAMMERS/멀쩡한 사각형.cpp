#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll w, ll h) {
    if (w > h)
        swap(w, h);

    ll tmp;
    while (w != 0) {
        tmp = h % w;
        h = w;
        w = tmp;
    }
    return h;
}

ll solution(int w, int h)
{
    ll lw = (ll)w;
    ll lh = (ll)h;
    return (lw*lh) - (lw + lh - gcd(lw, lh));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);

    solution();

    return 0;
}

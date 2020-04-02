#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MOD 1234567891
#define MAX 4000000
typedef long long ll;
using namespace std;
ll fac[MAX + 1], n, k, inv[MAX + 1];//inv[x]의 정의는 x의inverse가 아닌 x!의 inverse
ll power(ll x, ll y) {    //분할 정복을 이용하여 x^y 구하기
    ll ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret *= x;
            ret %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return ret;
}
int main() {
    fac[1] = 1;
    for (int i = 2; i <= MAX; i++)
        fac[i] = (fac[i - 1] * i) % MOD;            //factorial 전처리
    inv[MAX] = power(fac[MAX], MOD - 2);    //페르마의 소정리를 이용하여 fac(400만)의 inverse를 구함(이때 분할 정복을 이용하여 logP의 시간에 처리) 
    for (int i = MAX - 1; i > 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;    //inverse(fac(i))=inverse(fac(i+1))*(i+1)이라는 수식을 이용하여 전처리
    //총 O(N+logP)시간에 전처리를 끝냄 
    //전처리가 끝났기 때문에 어떤 쿼리가 들어와도 상수시간에 이항 계수를 계산 가능
    int tc; scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        scanf("%lld %lld", &n, &k);
        ll r = 0LL;
        if (n == k || !k) {
            r = 1;
        }
        else {
            r = (fac[n] * inv[n - k]) % MOD;
            r = (r * inv[k]) % MOD;
        }
        printf("#%d %lld\n", t, r);
    }
    return 0;
}
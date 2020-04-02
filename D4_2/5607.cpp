#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MOD 1234567891
#define MAX 4000000
typedef long long ll;
using namespace std;
ll fac[MAX + 1], n, k, inv[MAX + 1];//inv[x]�� ���Ǵ� x��inverse�� �ƴ� x!�� inverse
ll power(ll x, ll y) {    //���� ������ �̿��Ͽ� x^y ���ϱ�
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
        fac[i] = (fac[i - 1] * i) % MOD;            //factorial ��ó��
    inv[MAX] = power(fac[MAX], MOD - 2);    //�丣���� �������� �̿��Ͽ� fac(400��)�� inverse�� ����(�̶� ���� ������ �̿��Ͽ� logP�� �ð��� ó��) 
    for (int i = MAX - 1; i > 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;    //inverse(fac(i))=inverse(fac(i+1))*(i+1)�̶�� ������ �̿��Ͽ� ��ó��
    //�� O(N+logP)�ð��� ��ó���� ���� 
    //��ó���� ������ ������ � ������ ���͵� ����ð��� ���� ����� ��� ����
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
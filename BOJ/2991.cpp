#pragma warning(disable:4996)
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

int A, B, C, D, P, M, N;
//ù��° ���� ���
int Attack1(int man) {
    int dog1 = A + B;
    man = man % dog1;
    if (man == 0) return 0;
    if (0 < man && man <= A) return 1;
    if (man > A&& man < (A + B)) return 0;
}
//�ι�° ���� ���
int Attack2(int man) {
    int dog2 = C + D;
    man = man % dog2;
    if (man == 0) return 0;
    if (0 < man && man <= C) return 1;
    if (man > C&& man < (C + D)) return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

    cin >> A >> B >> C >> D;
    cin >> P >> M >> N;
    //��ü�� �����ϴ� ���� ��
    cout << Attack1(P) + Attack2(P) << endl;
    //������޿� �����ϴ� ���� ��
    cout << Attack1(M) + Attack2(M) << endl;
    //�Ź���޿� �����ϴ� ���� ��
    cout << Attack1(N) + Attack2(N) << endl;
	

	return 0;
}

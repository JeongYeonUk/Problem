#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

// ���ڿ� ���� N, �� ������ ���� Len, ������ �������� ���� Dn, ������ ��ġ K, ������� ���� �迭�� ���� Num_len, ���� Ans
int N, K, Len, Dn, Num_len, Ans;
// �Է¹��� ���ڿ� str
char Str[240];
// ������� ���� Num, 16���� ��ȯ�� ���� Mask
int Num[4100], Mask[128];

// 16���� ���ڿ� �ش��ϴ� ��ġ�� �� ���� �ִ´�.
void MakeMask(void)
{
    int i;
    for (i = '0'; i <= '9'; i++)
        Mask[i] = i - '0';
    for (i = 'A'; i <= 'F'; i++)
        Mask[i] = i - 'A' + 10;
}

// ������ �Է¹޴´�
void Input(void)
{
    scanf("%d %d", &N, &K);
    scanf("%s", Str);
}

// ���� ���ϴµ� �ʿ��� ��ó���� �Ѵ�
void PreProcess(void)
{
    int i;
    Num_len = 0;
    // Len�� N ������ 4
    Len = N >> 2;
    // Str�� ���� �ѹ� �� Str�� �ٿ��ش�
    for (i = 0; i < Len; i++)
        Str[i + N] = Str[i];
    // Dn�� 16���� (Len - 1) �ڸ����� ����� ���� �ʱ�ȭ
    Dn = (1 << ((Len - 1) * 4)) - 1;
}

// ���� �� �ִ� ��� ���ڸ� ���Ѵ�.
void GetNum(void)
{
    int i, num;
    num = 0;
    // ���� ó�� ���ڸ� ���Ѵ�.
    for (i = 0; i < Len; i++)
    {
        num <<= 4;
        num += Mask[Str[i]];
    }
    // ������� ���ڸ� Num �迭�� �ִ´�
    Num[Num_len++] = num;
    // ���ڸ� �ϳ��� �̷ﰡ�� �ݺ�
    for (i = 1; i < N; i++)
    {
        num &= Dn;
        num <<= 4;
        num += Mask[Str[i + (Len - 1)]];
        Num[Num_len++] = num;
    }
}

// ������� ���ڹ迭���� K��° ���ڸ� ���Ѵ�.
void GetAns(void)
{
    int i, j, temp, cnt;
    cnt = 1;
    // K��° �����̹Ƿ� K�� �ݺ�
    for (i = 0; i < K; i++)
    {
        for (j = i + 1; j < Num_len; j++)
        {
            if (Num[i] < Num[j])
            {
                temp = Num[i];
                Num[i] = Num[j];
                Num[j] = temp;
            }
            else if (Num[i] == Num[j])
            {
                Num[j] = 0;
                j--;
            }
        }
    }
}

int main(void)
{
    int T, T_i;
    MakeMask();
    scanf("%d", &T);
    for (T_i = 1; T_i <= T; T_i++)
    {
        Input();
        PreProcess();
        GetNum();
        GetAns();
        printf("#%d %d\n", T_i, Num[K - 1]);
    }
}
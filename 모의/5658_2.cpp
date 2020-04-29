#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

// 문자열 길이 N, 한 숫자의 길이 Len, 숫자의 나머지를 구할 Dn, 정답의 위치 K, 만들어진 숫자 배열의 길이 Num_len, 정답 Ans
int N, K, Len, Dn, Num_len, Ans;
// 입력받을 문자열 str
char Str[240];
// 만들어진 숫자 Num, 16진수 변환을 위한 Mask
int Num[4100], Mask[128];

// 16진수 문자에 해당하는 위치에 그 값을 넣는다.
void MakeMask(void)
{
    int i;
    for (i = '0'; i <= '9'; i++)
        Mask[i] = i - '0';
    for (i = 'A'; i <= 'F'; i++)
        Mask[i] = i - 'A' + 10;
}

// 변수를 입력받는다
void Input(void)
{
    scanf("%d %d", &N, &K);
    scanf("%s", Str);
}

// 답을 구하는데 필요한 전처리를 한다
void PreProcess(void)
{
    int i;
    Num_len = 0;
    // Len은 N 나누기 4
    Len = N >> 2;
    // Str의 끝에 한번 더 Str을 붙여준다
    for (i = 0; i < Len; i++)
        Str[i + N] = Str[i];
    // Dn은 16진수 (Len - 1) 자리수를 남기기 위해 초기화
    Dn = (1 << ((Len - 1) * 4)) - 1;
}

// 만들 수 있는 모든 숫자를 구한다.
void GetNum(void)
{
    int i, num;
    num = 0;
    // 가장 처음 숫자를 구한다.
    for (i = 0; i < Len; i++)
    {
        num <<= 4;
        num += Mask[Str[i]];
    }
    // 만들어진 숫자를 Num 배열에 넣는다
    Num[Num_len++] = num;
    // 숫자를 하나씩 미뤄가며 반복
    for (i = 1; i < N; i++)
    {
        num &= Dn;
        num <<= 4;
        num += Mask[Str[i + (Len - 1)]];
        Num[Num_len++] = num;
    }
}

// 만들어진 숫자배열에서 K번째 숫자를 구한다.
void GetAns(void)
{
    int i, j, temp, cnt;
    cnt = 1;
    // K번째 숫자이므로 K번 반복
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
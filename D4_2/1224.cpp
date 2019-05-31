#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

char infix[150];
char prefix[150];
char op[150];
void init()
{
  for (int i = 0; i < 150; ++i)
  {
    infix[i] = '\0';
    prefix[i] = '\0';
  }
}
int main()
{
  freopen("input.txt", "r", stdin);

  //int T; scanf("%d", &T);
  for (int cases = 1; cases <= 10; ++cases)
  {
    int N; scanf("%d", &N);
    scanf("%s", infix);
    int op_index = 0;
    int pre_index = 0;
    for (int i = 0; infix[i] != 0; ++i)
    {
      char c = infix[i];
      if (c == '(') continue;
      if (0 <= (c - '0') && (c - '0') < 10)
      {
        prefix[pre_index++] = c;
      }
      else if (c == ')')
      {
        prefix[pre_index++] = op[--op_index];
        op[op_index] = '\0';
      }
      else
      {
        op[op_index++] = c;
      }
    }
    if (op[0] != '\0')
    {
      for (int i = 0; op[i] != 0; ++i)
      {
        prefix[pre_index++] = op[i];
      }
    }

    while (true)
    {
      for (int i = 0; prefix[i] != 0; ++i)
      {
        if (prefix[i] == '+')
        {
          prefix[i] = '-';
          int flag = 0;
          int sum = 0;
          for (int j = i-1; j >= 0; --j)
          {            
            if (prefix[j] == '-') continue;
            sum += prefix[j] - '0';
            flag++;
            if (flag == 2)
            {
              prefix[j] = sum + '0';
              break;
            }
            prefix[j] = '-';
          }
        }
        else if (prefix[i] == '*')
        {
          prefix[i] = '-';
          int flag = 0;
          int sum = 0;
          int a = 0, b = 0;
          for (int j = i-1; j >= 0; --j)
          {
            if (prefix[j] == '-') continue;
            if (a != 0)
            {
              b = prefix[j] - '0';
              flag++;
            }
            else
            {
              a = prefix[j] - '0';
              flag++;
            }
            if (flag == 2)
            {
              sum = a * b;
              break;
            }
            prefix[j] = '-';
          }
        }
      }
      int ret = 0;
      for (int i = 0; i < N; ++i)
      {
        if (prefix[i] == '-')
          ret++;
      }
      if (ret == (N - 1))
        break;
    }

    printf("#%d %d\n", cases, prefix[0]);
  }

  return 0;
}

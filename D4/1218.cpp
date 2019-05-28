#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

const int MAX = 300;

struct STK
{
  char arr[MAX];
  int stk_point;
  int top_point;
  STK()
  {
    for (int i = 0; i < MAX; ++i)
      arr[i] = '\0';
    stk_point = 0;
    top_point = -1;
  }
  bool is_full()
  {
    if (stk_point == MAX)
      return true;
    else
      return false;
  }
  bool is_empty()
  {
    if (!stk_point)
      return true;
    else
      return false;
  }

  void push(char c)
  {
    if (is_full())
      return;
    arr[stk_point++] = c;
    top_point++;
  }
  void pop()
  {
    if (is_empty())
      return;
    arr[--stk_point] = '\0';
    top_point--;
  }

  char top()
  {
    return arr[top_point];
  }
};

int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);

  freopen("input.txt", "r", stdin);

  for (int cases = 1; cases <= 10; ++cases)
  {
    char input[300] = { 0, };
    int T; scanf("%d", &T);
    scanf("%s", input);

    STK stk;
    int index = 0;
    stk.push(input[index++]);
    while (index != T)
    {

      if (stk.is_empty())
      {
        stk.push(input[index++]);
        continue;
      }
      char temp = stk.top();
      if (temp == ')' || temp == '}' || temp == '>' || temp == ']')
        break;
      switch (temp)
      {
      case '(':
      {
        if (input[index] == ')')
        {
          stk.pop();
          index++;
        }
        else
        {
          stk.push(input[index++]);
        }
        break;
      }
      case '{':
      {
        if (input[index] == '}')
        {
          stk.pop();
          index++;
        }
        else
        {
          stk.push(input[index++]);
        }
        break;
      }
      case '<':
      {
        if (input[index] == '>')
        {
          stk.pop();
          index++;
        }
        else
        {
          stk.push(input[index++]);
        }
        break;
      }
      case '[':
      {
        if (input[index] == ']')
        {
          stk.pop();
          index++;
        }
        else
        {
          stk.push(input[index++]);
        }
        break;
      }
      default:
        break;
      }
    }
    printf("#%d ", cases);
    if (stk.is_empty())
      printf("1\n");
    else
      printf("0\n");
  }

  return 0;
}

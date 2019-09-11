#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
  int N; scanf("%d", &N);

  for (int i = N; i >= 0; --i) {
    if (i == 1) {
      printf("%d bottle of beer on the wall, %d bottle of beer. \n", i, i);
      printf("Take one down and pass it around, no more bottles of beer on the wall. \n\n");
    }
    else if (i == 0) {
      printf("No more bottles of beer on the wall, no more bottles of beer. \n");
      if (N != 1) {
        printf("Go to the store and buy some more, %d bottles of beer on the wall.", N);
      }
      else {
        printf("Go to the store and buy some more, %d bottle of beer on the wall.", N);
      }
    }
    else if(i-1 == 1){
      printf("%d bottles of beer on the wall, %d bottles of beer. \n", i, i);
      printf("Take one down and pass it around, 1 bottle of beer on the wall. \n\n");
    }
    else {
      printf("%d bottles of beer on the wall, %d bottles of beer. \n", i, i);
      printf("Take one down and pass it around, %d bottles of beer on the wall. \n\n", i-1);
    }
  }

  return 0;
}

n = int(input())

arr = [0] * 24

num = list(map(int, (input().split())))

for i in num:
    arr[i] += 1

for i in range(1, len(arr)+1):
    print(arr[i], end=' ')

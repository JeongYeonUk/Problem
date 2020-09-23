from itertools import count

a, d, n = map(int, input().split())

cnt = 1
for num in count(a, d):
    if cnt == n:
        print(num)
        break
    cnt += 1

from itertools import count

n = int(input())

sum = 0
for i in count(0):
    sum += i
    if sum >= n:
        break

print(sum)

a = int(input())

sum = 0
n = 1
while True:
    sum += n
    if sum >= a:
        break
    n += 1

print(n)

a, b, c = map(int, input().split())

day = 1
while True:
    if day % a == 0 and day % b == 0 and day % c == 0:
        break
    day += 1

print(day)

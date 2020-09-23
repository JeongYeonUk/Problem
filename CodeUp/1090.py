a, r, n = map(int, input().split())

for i in range(n-1):
    a = a * r

print(a)

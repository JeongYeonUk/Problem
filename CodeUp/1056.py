a, b = map(int, input().split())
print((a and b ^ 1) or (a ^ 1 and b))

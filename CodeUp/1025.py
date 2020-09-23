num = int(input())
t = 10000
for i in range(0, 5):
    print("[%d]" % ((num // t) * t))
    num %= t
    t //= 10

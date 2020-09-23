R, G, B = map(int, input().split())

cnt = 0
for r in range(0, R):
    for g in range(0, G):
        for b in range(0, B):
            print(r, g, b)
            cnt += 1
print(cnt)

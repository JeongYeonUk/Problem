a, b, c = map(int, input().split())
li = []
li.append(a)
li.append(b)
li.append(c)
for l in li:
    if not l & 1:
        print(l)

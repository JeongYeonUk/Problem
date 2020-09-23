n = input()
li = list(map(int, input().split()))

li.reverse()
for i in range(len(li)):
    print(li[i], end=' ')

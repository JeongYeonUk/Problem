def switch(a):
    return {
        'A': '10',
        'B': '11',
        'C': '12',
        'D': '13',
        'E': '14',
        'F': '15'
    }[a]


a = input()

a = int(switch(a))
for i in range(1, 16):
    ret = a * i

    print("%X*%X=%X" % (a, i, ret))

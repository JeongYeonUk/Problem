def switch(a):
    return {'A': 'best!!!', 'B': 'good!!', 'C': 'run!', 'D': 'slowly~'}.get(a, 'what?')


a = input()
print(switch(a))

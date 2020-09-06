def solution(s):

    return (len(s) == 4 or len(s) == 6) and s.isdigit() or False


def solution2(s):
    return s.isdigit() and len(s) in (4, 6)

def solution(n, lost, reserve):

    lost = list(map(lambda x: x - 1, lost))
    reserve = list(map(lambda x: x - 1, reserve))
    answer = 0

    dress = [1] * n

    for l in lost:
        dress[l] -= 1
    for r in reserve:
        dress[r] += 1

    for idx, d in enumerate(dress):
        if idx == 0:
            if dress[idx] == 0:
                if dress[idx + 1] == 2:
                    dress[idx] += 1
                    dress[idx + 1] -= 1
        elif idx == len(dress) - 1:
            if dress[idx] == 0:
                if dress[idx - 1] == 2:
                    dress[idx] += 1
                    dress[idx - 1] -= 1
        else:
            if dress[idx] == 0:
                if dress[idx + 1] == 2:
                    dress[idx] += 1
                    dress[idx + 1] -= 1
                elif dress[idx - 1] == 2:
                    dress[idx] += 1
                    dress[idx - 1] -= 1

    answer = 0
    for d in dress:
        if d:
            answer += 1
    return answer


def solution2(n, lost, reserve):
    _reserve = [r for r in reserve if r not in lost]
    _lost = [l for l in lost if l not in reserve]
    for r in _reserve:
        f = r - 1
        b = r + 1
        if f in _lost:
            _lost.remove(f)
        elif b in _lost:
            _lost.remove(b)
    return n - len(_lost)


print(solution2(5, [2, 4], [1, 3, 5]))


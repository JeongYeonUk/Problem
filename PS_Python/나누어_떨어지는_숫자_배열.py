def solution(arr, divisor):
    answer = []

    for a in arr:
        if a % divisor == 0:
            answer.append(a)

    answer.sort()
    if len(answer) == 0:
        answer.append(-1)

    return answer


def solution2(arr, divisor):
    return sorted([n for n in arr if n % divisor == 0]) or [-1]


print(solution([5, 9, 7, 10], 5))


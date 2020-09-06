def solution(arr):
    answer = []
    answer.append(arr[0])
    for idx, num in enumerate(arr):
        if idx == 0:
            continue
        if answer[-1] != num:
            answer.append(num)

    return answer


print(solution([1, 1, 3, 3, 0, 1, 1]))


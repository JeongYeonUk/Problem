def solution(participant, completion):

    participant.sort()
    completion.sort()

    for idx, c in enumerate(completion):
        if participant[idx] != completion[idx]:
            return participant[idx]

    return participant[-1]


answer = solution(
    ["marina", "josipa", "nikola", "vinko", "filipa"],
    ["josipa", "filipa", "marina", "nikola"],
)

answer2 = solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"])
print(answer)
print(answer2)


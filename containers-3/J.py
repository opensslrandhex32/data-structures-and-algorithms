N = int(input())

for _ in range(N):
    data = input().split()

    K = int(data[0])
    priorities = list(map(float, data[1:]))

    target = sorted(priorities)

    stack = []
    j = 0
    for pr in priorities:
        stack.append(pr)

        while stack and stack[-1] == target[j]:
            stack.pop()
            j += 1

            if j == K:
                break

    if not stack:
        print(1)
    else:
        print(0)
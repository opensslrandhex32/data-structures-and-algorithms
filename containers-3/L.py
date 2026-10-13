lst = list(map(int, input().split()))
N = lst[0]
heights = lst[1:]
stack = []
res = 0

for i in range(N + 1):
    curHeight = heights[i] if i < N else 0

    while stack and heights[stack[-1]] >= curHeight:
        h = heights[stack.pop()]

        left = stack[-1] if stack else -1

        w = i - left - 1
        res = max(res, h * w)

    stack.append(i)

print(res)
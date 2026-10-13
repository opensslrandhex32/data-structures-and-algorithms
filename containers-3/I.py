data = list(map(int, input().split()))
N = data[0]
colors = data[1:]

stack = []
removed = 0

i = 0
while i < N:
    color = colors[i]

    count = 0
    while i < N and colors[i] == color:
        count += 1
        i += 1

    if stack and stack[-1][0] == color:
        count += stack.pop()[1]

    if count >= 3:
        removed += count
    else:
        stack.append((color, count))

print(removed)

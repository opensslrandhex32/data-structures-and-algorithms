N = int(input())
a = list(map(int, input().split()))

stack = []
needed = 1

for x in a:
    stack.append(x)

    while stack and stack[-1] == needed:
        stack.pop()
        needed += 1

print("YES" if needed == N + 1 else "NO")
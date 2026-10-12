from collections import deque

N = int(input())

left = deque()
right = deque()

for _ in range(N):
    command = input().split()

    if command[0] == "+":
        right.append(int(command[1]))
    elif command[0] == "*":
        right.appendleft(int(command[1]))
    elif command[0] == "-":
        print(left.popleft())

    if len(left) < len(right):
        left.append(right.popleft())
    

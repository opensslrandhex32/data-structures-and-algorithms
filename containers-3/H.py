import sys
from collections import deque

input = sys.stdin.buffer.readline

N = int(input())
left = deque()
right = deque()
result = []

for _ in range(N):
    command = input().split()

    if command[0] == b"+":
        right.append(int(command[1]))
    elif command[0] == b"*":
        right.appendleft(int(command[1]))
    else: # command[0] == b"-"
        result.append(str(left.popleft()))

    if len(left) < len(right):
        left.append(right.popleft())
    

sys.stdout.write("\n".join(result))
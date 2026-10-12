from collections import deque

    
first =  deque(map(int, input().split()))
second = deque(map(int, input().split()))

for move in range(1, 10**6 + 1):
    a, b = first.popleft(), second.popleft()

    if (a == 0 and b == 9) or (a > b and not (a == 9 and b == 0)):
        first.extend([a, b])
    else:
        second.extend([a, b])

    if not first:
        print("second", move)
        break

    if not second:
        print("first", move)
        break

else:
    print("botva")

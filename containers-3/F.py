from collections import deque

N, K = map(int, input().split())
a = list(map(int, input().split()))

indexes = deque()

for i in range(N):
    if indexes and indexes[0] <= i - K:
        indexes.popleft()

    while indexes and a[indexes[-1]] >= a[i]:
        indexes.pop()

    indexes.append(i)

    if i >= K - 1:
        print(a[indexes[0]])

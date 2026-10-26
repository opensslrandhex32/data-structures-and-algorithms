import heapq

N = int(input())
heap = list(map(int, input().split())) # (пока что не heap, только после выполнения сл. строки)
heapq.heapify(heap)

res = 0
while len(heap) >= 2:
    s = heapq.heappop(heap) + heapq.heappop(heap)
    res += s * 0.05
    heapq.heappush(heap, s)

print(f'{res:.2f}')


import heapq

N = int(input())

lst = []
for _ in range(N):
    T, L = map(int, input().split()) # T - вр. прибытия, L - вр. обработки. T + L - вр. финиша
    lst.append((T, L))
lst.sort()

finish_times = []

for T, L in lst:
    if finish_times and T >= finish_times[0]:
        heapq.heappop(finish_times)
    heapq.heappush(finish_times, T + L)

print(len(finish_times))
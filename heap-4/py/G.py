import heapq

n = int(input())

colony_sizes = []
birth_events = []  # heap[tuple(birth_time, aq_index)]

for aquarium in range(n):
    f = int(input())
    colony_sizes.append(f)

    first_birth_time = max(1000 - f, 1)
    heapq.heappush(birth_events, (first_birth_time, aquarium))

current_time = current_aquarium = 0

while True:
    birth_time, aquarium = heapq.heappop(birth_events)
    arrival_time = current_time + abs(current_aquarium - aquarium)

    if arrival_time > birth_time:
        print(birth_time)
        break

    current_time = birth_time
    current_aquarium = aquarium
    colony_sizes[aquarium] += 1

    next_birth_time = birth_time + max(1000 - colony_sizes[aquarium], 1)
    heapq.heappush(birth_events, (next_birth_time, aquarium))


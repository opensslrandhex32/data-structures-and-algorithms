class Heap:
    def __init__(self):
        self.data = []

    def sift_up(self):
        i = len(self.data) - 1
        while i > 0 and self.data[i] > self.data[(i - 1) // 2]:
            self.data[i], self.data[(i - 1) // 2] = self.data[(i - 1) // 2], self.data[i]
            i = (i - 1) // 2

    def sift_down(self):
        i = 0
        sz = len(self.data)

        while 2 * i + 1 < sz:
            left = 2 * i + 1
            right = 2 * i + 2

            largest_child = left
            if (
                    right < sz
                    and self.data[right] > self.data[left]
            ):
                largest_child = right

            if self.data[i] >= self.data[largest_child]:
                break

            self.data[i], self.data[largest_child] = (
                self.data[largest_child],
                self.data[i],
            )
            i = largest_child

    def insert(self, value):
        self.data.append(value)
        self.sift_up()

    def extract_max(self):
        self.data[0], self.data[-1] = self.data[-1], self.data[0]
        maximum = self.data.pop()
        self.sift_down()
        return maximum


command_count = int(input())
heap = Heap()

# “0 <число>” или “1”, соответственно, операции Insert(<число>) и Extract
for _ in range(command_count):
    command = list(map(int, input().split()))
    if command[0] == 0:
        heap.insert(command[1])
    else:
        print(heap.extract_max())

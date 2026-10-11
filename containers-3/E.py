class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None


class Deque:
    def __init__(self) -> None:
        self.sz = 0
        self.head = None
        self.tail = None

    def push_front(self, value):
        node = Node(value)
        if not self.head:
            self.head = self.tail = node
        else:
            self.head.prev = node
            node.next = self.head
            self.head = node
        self.sz += 1

    def push_back(self, value):
        node = Node(value)
        if not self.tail:
            self.head = self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
        self.sz += 1

    def pop_front(self):
        if not self.head:
            return "error"
        temp = self.head.value
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        else:
            self.head = self.tail = None
        self.sz -= 1
        return temp

    def pop_back(self):
        if not self.tail:
            return "error"
        temp = self.tail.value
        self.tail = self.tail.prev
        if self.tail:
            self.tail.next = None
        else:
            self.head = self.tail = None
        self.sz -= 1
        return temp
    
    def front(self):
        if self.head is None:
            return "error"
        return self.head.value

    def back(self):
        if self.tail is None:
            return "error"
        return self.tail.value

    def size(self):
        return self.sz

    def clear(self):
        self.head = None
        self.tail = None
        self.sz = 0


dq = Deque()

while True:
    command = input().split()

    if command[0] == "push_front":
        dq.push_front(int(command[1]))
        print("ok")

    elif command[0] == "push_back":
        dq.push_back(int(command[1]))
        print("ok")

    elif command[0] == "pop_front":
        print(dq.pop_front())

    elif command[0] == "pop_back":
        print(dq.pop_back())

    elif command[0] == "front":
        print(dq.front())

    elif command[0] == "back":
        print(dq.back())

    elif command[0] == "size":
        print(dq.size())

    elif command[0] == "clear":
        dq.clear()
        print("ok")

    elif command[0] == "exit":
        print("bye")
        break

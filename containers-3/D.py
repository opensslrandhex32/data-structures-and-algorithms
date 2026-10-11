
class Queue:
    def __init__(self):
        self.input_stack = []
        self.output_stack = []

    def push(self, value):
        self.input_stack.append(value)

    def move(self):
        if not self.output_stack:
            while self.input_stack:
                self.output_stack.append(self.input_stack.pop())

    def pop(self):
        self.move()

        if not self.output_stack:
            return "error"

        return self.output_stack.pop()

    def front(self):
        self.move()

        if not self.output_stack:
            return "error"

        return self.output_stack[-1]

    def size(self):
        return len(self.input_stack) + len(self.output_stack)

    def clear(self):
        self.input_stack.clear()
        self.output_stack.clear()


queue = Queue()

while True:
    command = input().split()

    if command[0] == "push":
        queue.push(int(command[1]))
        print("ok")

    elif command[0] == "pop":
        print(queue.pop())

    elif command[0] == "front":
        print(queue.front())

    elif command[0] == "size":
        print(queue.size())

    elif command[0] == "clear":
        queue.clear()
        print("ok")

    elif command[0] == "exit":
        print("bye")
        break

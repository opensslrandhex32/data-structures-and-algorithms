class Stack:
    def __init__(self):
        self.data = []

    def push(self, value):
        self.data.append(value)

    def pop(self):
        if not self.data:
            return "error"
        return self.data.pop()

    def back(self):
        if not self.data:
            return "error"
        return self.data[-1]

    def size(self):
        return len(self.data)

    def clear(self):
        self.data.clear()


stack = Stack()

while True:
    command = input().split()

    if command[0] == "push":
        stack.push(int(command[1]))
        print("ok")

    elif command[0] == "pop":
        print(stack.pop())

    elif command[0] == "back":
        print(stack.back())

    elif command[0] == "size":
        print(stack.size())

    elif command[0] == "clear":
        stack.clear()
        print("ok")

    elif command[0] == "exit":
        print("bye")
        break

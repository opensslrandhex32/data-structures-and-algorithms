s = input().split()
stack = []

for c in s: 
    if c in "+-*":
        b, a = stack.pop(), stack.pop() 
        if c == "+": 
            stack.append(a + b)
        elif c == "-": 
            stack.append(a - b) 
        else: 
            stack.append(a * b)
    else: 
        stack.append(int(c))

print(stack.pop())
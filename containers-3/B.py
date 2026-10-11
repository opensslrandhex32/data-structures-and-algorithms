s = input()
stack = []
closeToOpen = {')': '(', ']': '[', '}': '{'}

for c in s:
    if c in "([{":
        stack.append(c)
    elif not stack or stack.pop() != closeToOpen[c]:
        print("no")
        break
else:
    print("yes" if not stack else "no")

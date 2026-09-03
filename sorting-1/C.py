A = list( map(int, input().split()))

def BubbleSort(A):
    n = len(A)
    is_sorted = False

    while not is_sorted:
        is_sorted = True
        for i in range(n - 1):
            if A[i] < A[i + 1]:
                A[i], A[i + 1] = A[i + 1], A[i]
                is_sorted = False
    return A

print(*BubbleSort(A))
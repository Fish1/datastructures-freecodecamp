
data = [ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 ]
data.reverse()

def heapify(arr, index):

    largestIndex = index
    leftIndex = 2 * index + 1
    rightIndex = 2 * index + 2

    if leftIndex < len(arr) and arr[leftIndex] < arr[largestIndex]:
        largestIndex = leftIndex

    if rightIndex < len(arr) and arr[rightIndex] < arr[largestIndex]:
        largestIndex = rightIndex

    if largestIndex != index:
        arr[index], arr[largestIndex] = arr[largestIndex], arr[index]

        heapify(arr, largestIndex)

def buildHeap(arr):
    startIndex = len(arr)

    for i in range(startIndex, -1, -1):
        heapify(arr, i)

def printHeap(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()

printHeap(data)
buildHeap(data)
printHeap(data)

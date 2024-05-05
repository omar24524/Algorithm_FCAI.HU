def sortReverse(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key > arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr

def interleave(arr1, arr2):
    if not arr1:
        return arr2
    if not arr2:
        return arr1
    return [arr2[0]]+interleave(arr2[1:], arr1)
def wiggleAtya2(arr:list):
    arr= sortReverse(arr)#any sorting algorithm
    mid= len(arr)>>1
    return interleave(arr[:mid], arr[mid:])

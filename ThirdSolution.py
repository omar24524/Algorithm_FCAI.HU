def interleave(arr1, arr2):
    if not arr1:
        return arr2
    if not arr2:
        return arr1
    return [arr2[0]]+interleave_arrays(arr2[1:], arr1)
def wiggleAtya2(arr:list):
    arr= sorted(arr)#any sorting algorithm
    mid= len(arr)>>1
    arr= arr[::-1]#reverse, could be done with a loop
    return interleave(arr[:mid], arr[mid:])

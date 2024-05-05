def IDX(i, n):
    return (2 * i + 1) % (n | 1)

def wiggleInterleaved4(arr: list):
    arr.sort()
    n = len(arr)
    mid = arr[n >> 1];
    i = 0;
    j = 0;
    k = n - 1
    while j <= k:
        if arr[IDX(j, n)] > mid:
            arr[IDX(j, n)], arr[IDX(i, n)] = arr[IDX(i, n)], arr[IDX(j, n)]
            i += 1;
            j += 1
        elif arr[IDX(j, n)] < mid:
            arr[IDX(j, n)], arr[IDX(k, n)] = arr[IDX(k, n)], arr[IDX(j, n)]
            k -= 1
        else:
            j += 1
    return arr

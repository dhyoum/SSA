def bsearch(arr, key):
    start = 0
    end = len(arr)-1
    while start <= end:
        mid = (start + end)//2
        if key == arr[mid]:
            return True
        elif key > arr[mid]:
            start = mid + 1
        else:
            end = mid + 1

    return False

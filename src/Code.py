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

def lower_bound(arr, key): # key 이상인 수가 처음으로 등장하는 위치
    start = 0
    end = len(arr)-1
    while start < end:
        mid = (start + end)//2
        if arr[mid] < key:
            start = mid + 1
        else:
            end = mid

    return end

def upper_bound(arr, key):  # key 큰 수가 처음으로 등장하는 위치
    start = 0
    end = len(arr)-1
    while start < end:
        mid = (start + end)//2
        if arr[mid] <= key:
            start = mid + 1
        else:
            end = mid

    return end

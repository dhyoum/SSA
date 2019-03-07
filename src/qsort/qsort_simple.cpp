void QuickSort(int *base, int start, int end, int max)
{
    if (start >= end || start >= max) return;
     
    int left = start - 1, right = end + 1;
    int pivot = base[(start + end) / 2];
     
    while (1)
    {
        while (base[++left] > pivot);
        while (base[--right] < pivot);
        if (left >= right) break;
        swap(base[left], base[right]);
    }
     
    QuickSort(base, start, left - 1, max);
    QuickSort(base, right + 1, end, max);
}

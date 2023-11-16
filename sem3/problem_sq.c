unsigned partition(int *arr, unsigned low, unsigned high) {
    int temp;
    int pivot = arr[low];
    unsigned i = low + 1;
    unsigned j = high;
    while (1) {
        int temp;
        while (arr[i] <= pivot && i <= high) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i >= j) {
            break;
        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

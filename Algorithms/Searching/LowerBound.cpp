int lower_bound(int arr[], int N, int X) {
    int low = 0;
    int high = N;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (X <= arr[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
   
    if(low < N && arr[low] < X) {
       low++;
    }

    return low;
}

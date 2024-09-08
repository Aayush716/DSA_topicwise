void insertionSort(int arr[], int n)
{
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }//inner loop is only for swapping elements from unsorted to sorted array ,swap till min element comes at start
    }
}
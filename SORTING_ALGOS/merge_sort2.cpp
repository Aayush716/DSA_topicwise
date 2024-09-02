#include <iostream>
#include <vector>
using namespace std;


void merge(int *arr,int low,int mid,int high){
    int n1 = mid-low+1;
    int n2 = high-mid;
    int arr1[n1]; int p1=0;
    int arr2[n2]; int p2=0;

    //copy elements from orignal array to arr1 and arr2 respectively
    int k=0;
    for(int i=low;i<=mid;i++){
        arr1[k++] = arr[i];
    }
    k=0;
    for(int i=mid+1;i<=high;i++){
        arr2[k++] = arr[i];
    }

    //compare them and arrange in sorted manner
    k=low;//--------------------------------------------this line is important and i miss it.
    while(p1!=n1 && p2!=n2){
        if(arr1[p1]<arr2[p2]){
            arr[k++] = arr1[p1++];
        }
        else{
            arr[k++] = arr2[p2++];
        }
    }
    
    //enter the remaining ones if left
    while(p1!=n1){
        arr[k++] = arr1[p1++];
    }
    while(p2!=n2){
        arr[k++] = arr2[p2++];
    }

}


void mergesort(int *arr,int low,int high){
    int mid = (low+high)/2;
    if(low>=high){
        return;
    }
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main() {
    int num[] = {2,4,6,1,5,8,9,3,2,10,11,5,7};
    int n = sizeof(num)/sizeof(num[0]);
    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
    }

    mergesort(num,0,n-1);

    cout<<"\nafter merge sort array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
    }
}
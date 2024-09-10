#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr,int start,int mid,int end){
    int n1 = mid-start+1;
    int n2 = end - mid;
    int arr1[n1];
    int arr2[n2];
    int p1=0;
    int p2=0;
    int k = start;
    //need to copy elements to temporary array
    for(int i=0;i<n1;i++){
        arr1[i] = arr[k++];
    }
    k=mid+1;
    for(int i=0;i<n2;i++){
        arr2[i] = arr[k++];
    }
    k=start;//intialize k to orignal value
    while(p1!=n1 && p2!=n2){
        if(arr1[p1]<arr2[p2]){
            arr[k] = arr1[p1];
            k++;
            p1++;
        }
        else{
            arr[k] = arr2[p2];
            k++;
            p2++;
        }
    }
//will go in either of below while loops to copy remaining elements
    while(p1!=n1){
        arr[k] = arr1[p1];
        k++;
        p1++;
    }
    while(p2!=n2){
        arr[k] = arr2[p2];
        k++;
        p2++;
    }
}

void mergesort(int *arr,int start,int end){
    if(start>=end){//conditon to stop
        return;
    }
    int mid = (start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
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
#include <bits/stdc++.h>

void selectionSort(vector<int>&arr) {
    
    for(int i=0;i<arr.size();i++){
        int mindex = i;
        for(int j=i;j<arr.size();j++){
            if(arr[j]<arr[mindex]){
                mindex = j;
            }//find the element with mindex
        }
        swap(arr[i],arr[mindex]);
    }
    
}
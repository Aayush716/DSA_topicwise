#include <iostream>
#include <map>
using namespace std;

int main(){
    map< int, int> mp;  //key value pair in map the first is key that is 'element' and the value is 'count' of that element 
    int arr[] = {5,2,5,5,3,3,5,1,6,4,4}; //array with random elements
    int size = sizeof(arr)/sizeof(int);
    for(int i=0;i<size;i++){
        mp[arr[i]]++;  //this increment increases the count of occurence of that particular element
    }
    map<int,int>:: iterator itr = mp.begin();
    while(itr!=mp.end()){
        cout<<" key = "<<itr->first<<" value/occurence of key = "<<itr->second<<endl;
        itr++;
    }

    cout<<"\nprinting key value pairs using auto\n";
    for(auto x: mp){
        cout<<" key = "<<x.first<<" value = "<<x.second<<endl;
    }
}

/*
To check if a element is present in the map or always use  
map<char,int> mp;
if(mp.find(s[j])!=mp.end()){//very important
                    mp2[s[j]]++;
  }

mp.find(s[j])!=mp.end(){
    this means that element is present
}

*/
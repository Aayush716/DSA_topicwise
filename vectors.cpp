#include <bits/stdc++.h>
using namespace std;

int main(){

    cout<<"printing without iterator\n";
    vector<int> nums;
    //to push element inside a vector we use nums.push_back(value);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(6);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    cout<<"\n to get topmost entry of vector we use nums.back() and to get first entry we use nums.front()";
    cout<<"\n latest entry = "<<nums.back();
    cout<<"\n first entry = "<<nums.front();
    
    cout<<"\nprinting using iterator\n";
    vector<int>::iterator itr = nums.begin();
    for(itr=nums.begin(); itr!=nums.end(); itr++){
        cout<<*(itr)<<" ";
    }

    cout<<"\nprinting using auto\n";
    for(auto x: nums){
        cout<<x<<" ";
    }

    cout<<"\ninserting element after 2nd positon\n";
    nums.insert(nums.begin()+2, 100); //inserting 100 after 2nd position
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    cout<<"\nremoving the element at 3rd positon\n";
    nums.erase(nums.begin()+2);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    cout<<"\nto sort the vector we use sort function\n";
    sort(nums.begin(),nums.end()); //sort the vector from begin() to end()
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    //vector of vectors means there is a vector and each container of the vector is of type vector
    vector<vector<int>> nums2; //a vector nums2 containing 5 containers ,each container is a vector of dynamic size
    vector<int> temp;
    //after pushing values in temp we can push temp in nums2 eg:- nums2.push_back(temp)

    //to clear entire vector we use nums.clear()


}
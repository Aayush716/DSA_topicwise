// C++ program to demonstrate sorting in
// vector of pair according to 1st element
#include <bits/stdc++.h>

//#include <pair>
using namespace std;
 
int main()
{    
    int arr[] = {10, 20, 5, 40 };
    int arr2[] = {30, 60, 20, 50};
    vector<pair<int,int>> vec;
    pair<int,int> p;
    int n = (sizeof(arr)/sizeof(int));
    for(int i=0;i<n;i++){
        p.first = arr[i];
        p.second = arr2[i];
        vec.push_back(p);//pushing a pair type in vector
    }
    cout<<"\nvector before sorting ";
    for(int i=0;i<vec.size();i++){
        cout<<"\n first = "<<vec[i].first<<" second = "<<vec[i].second;
    }
    sort(vec.begin(),vec.end());
    cout<< "\nThe vector after sort operation is:" ;
    for(int i=0;i<vec.size();i++){
        cout<<"\n first = "<<vec[i].first<<" second = "<<vec[i].second;
    }

    return 0;
}
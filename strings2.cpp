#include <bits/stdc++.h>
using namespace std;

int main(){

    cout<<"\nto genrate all possible substring of a string is:";
    string s = "Aayush";
    int n = s.size();
    string temp;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            temp = s.substr(i,j-i+1);//(start_index, length_of substring)
            cout<<"\nsubstring = "<<temp;
        }
    }
}
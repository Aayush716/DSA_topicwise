//check whether string uis plainrome or not

#include <bits/stdc++.h>

bool checkpalinrome(string& str,int index){
    if(index>=(str.size()/2)){
        return  true;
    }//this true will be recursively passed to all the functions and atlast will be send to isPalindrome 
    if(str[index]==str[str.size()-1-index]){
        return checkpalinrome(str,++index);
    }
    return false;
}

bool isPalindrome(string& str) {
    bool ans = checkpalinrome(str,0);
    return ans;
}

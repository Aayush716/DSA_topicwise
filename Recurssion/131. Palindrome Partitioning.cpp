/*
https://leetcode.com/problems/palindrome-partitioning/description/
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> ans;
    int n;

    bool ispalindrome(string t){
        int l=0;
        int r=t.size()-1;
        while(l<=r){
            if(t[l]!=t[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void fun(int i,string s, vector<string> &temp){
        if(i>=n){//if we are able to reach at end of string that means we created all partions such that each one is a palindrome
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<n;j++){
            if(ispalindrome(s.substr(i,j-i+1))){
                temp.push_back(s.substr(i,j-i+1));
                fun(j+1,s,temp);//look for further partions 
                temp.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<string> temp;
        n = s.size();
        fun(0,s,temp);   
        return ans; 
    }
};

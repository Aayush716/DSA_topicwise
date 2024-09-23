/*

You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping
 substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present
in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. 
There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. 
The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. 
Hence, we return 3.

https://leetcode.com/problems/extra-characters-in-a-string/description


*/

//Note :- In dp for memoization the dimenson of dp is determined by things that change at every iteration
//for instance in subset sum problem index change and our target change hence dp was 2Dimensional
//In our case only index i chnages and dp[i] stores min characters need to be removed hence our dp is single dimensional


class Solution {
public:
    int fun(int i,string &s,unordered_set<string> &st,int &n,vector<int> &dp){
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){//dp here is 1D because we only keep index or things that change at every iteration
            return dp[i];//in out case only index changes rest all remain same
        }

        int pick = n;
        for(int j=i;j<n;j++){
            string temp = s.substr(i,j-i+1);//removed all substrings of s from index i till nth index
            if(st.find(temp)!=st.end()){//since we found a substring till j we will ceck from index j+1 now
                pick = min(pick,fun(j+1,s,st,n,dp));
            }
        }

        int dont_pick = 1 + fun(i+1,s,st,n,dp);
       

        return dp[i] = min(dont_pick,pick);
        //return result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
       int n = s.size();
       unordered_set<string> st;
       for(auto x: dictionary){
            st.insert(x);
       }//transfered dictionary to set st so that easy to search
       vector<int> dp(n,-1);
       int ans =  fun(0,s,st,n,dp);//index , string and dictonary given
       return ans;
    }
};

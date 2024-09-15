/*
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.

https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/


*/

class Solution {
public:
    string fun(vector<int> &vowel_count){
        string temp;
        for(int i=0;i<5;i++){
            if(vowel_count[i]==0){
                temp = temp + '0';
            }
            else{
                temp = temp + '1';
            }
        }
        return temp;
    }

    int findTheLongestSubstring(string s) {
        vector<int> vowel_count(5,0);
        //   a   e  i  o  u
        //   0   0  0  0  0 
        map<string,int> mp;//string of vowel count (even/odd) and value = index
        mp["00000"] = -1;//intial conditon
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                vowel_count[0]++;
                vowel_count[0] = vowel_count[0]%2;
            }
            else if(s[i]=='e'){
                vowel_count[1]++;
                vowel_count[1] = vowel_count[1]%2;
            }
            else if(s[i]=='i'){
                vowel_count[2]++;
                vowel_count[2] = vowel_count[2]%2;
            }
            else if(s[i]=='o'){
                vowel_count[3]++;
                vowel_count[3] = vowel_count[3]%2;
            }
            else if(s[i]=='u'){
                vowel_count[4]++;
                vowel_count[4] = vowel_count[4]%2;
            }

            string temp = fun(vowel_count);
           // cout<<"at i = "<<i<<" temp = "<<temp<<endl;
            //we are checking when was count of all vowels even previously and we subtract 
            //current index with previous index where all vowels count was even
            //do not worry about consonants
            if(mp.find(temp)!=mp.end()){
                ans = max(ans,i - mp[temp]);//current index - index at which this string was repeated
            }
            else{
                mp[temp] = i;
            }
        }

        return ans;
    }
};
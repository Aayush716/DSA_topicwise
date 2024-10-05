/*
567. Permutation in String
Solved
Medium
Topics
Companies
Hint
Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //suppose s1 size = n  then sort s1 and make window size in s2 = n sort it and check if i equal to s1's
        //sorted version

        int n1 = s1.size();
        sort(s1.begin(),s1.end());//s1 is sorted
        int n2 = s2.size();

        //bou
        if(n1>n2){
            return false;
        }

        //sliding window approach where window is fixed of length of n1
        int i=0;//1st pointer
        int j=n1-1;//2nd pointer
        while(j<n2){
            string temp = s2.substr(i,n1); // {start_index, length of substring we want} length of substring is fixed that is n2
            sort(temp.begin(),temp.end());
           // cout<<"s1 = "<<s1<<" temp = "<<temp<<endl;
            if(s1==temp){
                return true;
            }
            //increase both pointers by 1 keeping window length the same
            i++;
            j++;
        }
        return false;
    }
};

//2nd approach:-
//instead of sorting temp (window of size n1 in s2) we can compare character frequency of s1 and temp
//if at any time we find this 2 map freq same return true.


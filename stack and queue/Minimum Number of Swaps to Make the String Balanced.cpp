/*
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
 

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
*/

class Solution {
public:
    int minSwaps(string s) {
        //final answer is = (number of unbalanced opening brackets + 1)/2
        //or = (number of unbalanced closing bracket + 1)/2
        
        //pop the already balanced brackets 

        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push('[');
            }
            else if(!st.empty()){ //balancing the correct opening and closing brackets already present
                st.pop();
            }
        }

        int n_unbalanced_opening = st.size();

        return (n_unbalanced_opening + 1)/2;
    }
};

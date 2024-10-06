/*
You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 

Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.
*/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> nums1;
        vector<string> nums2;
        int n1 = sentence1.size();
        int n2 = sentence2.size();
        for(int i=0;i<n1;i++){
            string temp;
            while(i<n1 && sentence1[i]!=' '){
                temp += sentence1[i];
                i++;
            }
            nums1.push_back(temp);
        }

         for(int i=0;i<n2;i++){
            string temp;
            while(i<n2 && sentence2[i]!=' '){
                temp += sentence2[i];
                i++;
            }
            nums2.push_back(temp);
        }

       int l1=0 , r1=nums1.size()-1;//1st and last pointer for nums1
       int l2=0 , r2=nums2.size()-1;//1st and last pointer for nums2

       while(l1<=r1 && l2<=r2){
            if(nums1[l1]==nums2[l2]){
                l1++;
                l2++;
            }
            else if(nums1[r1]==nums2[r2]){
                r1--;
                r2--;
            }
            else{
                return false;
            }
       }

        return true;
    }
};

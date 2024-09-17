/*
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

*/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordFreq1;
        unordered_map<string, int> wordFreq2;
        
        vector<string> sen1Words = split(s1);
        vector<string> sen2Words = split(s2);
        
        for (const auto& word : sen1Words) {
            wordFreq1[word] += 1;
        }
        
        for (const auto& word : sen2Words) {
            wordFreq2[word] += 1;
        }
        
        vector<string> uncommons;
        
        for (const auto& entry : wordFreq1) {
            string word = entry.first;
            int wordFreq = entry.second;
            if (wordFreq == 1 && wordFreq2.find(word) == wordFreq2.end()) {
                uncommons.push_back(word);
            }
        }
        
        for (const auto& entry : wordFreq2) {
            string word = entry.first;
            int wordFreq = entry.second;
            if (wordFreq == 1 && wordFreq1.find(word) == wordFreq1.end()) {
                uncommons.push_back(word);
            }
        }
        
        return uncommons;
    }

private:
    vector<string> split(const string& str) {
        vector<string> result;
        string word;
        for (char ch : str) {
            if (ch == ' ') {
                if (!word.empty()) {
                    result.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            result.push_back(word);
        }
        return result;
    }
};
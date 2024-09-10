#include <iostream>
#include <string>
using namespace std;


string reversePrefix(string word, char ch) {
    int j = word.find(ch); // word.find(ch)  return the index of our character ch if found else will return -1
    if (j != -1) {
        reverse(word.begin(), word.begin() + j + 1); //function to reverse a string
    }
    return word;
}

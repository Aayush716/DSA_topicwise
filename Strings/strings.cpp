#include <iostream>
#include <string>
using namespace std;

/*
int index = s.find(ch);/find the character
string substr = s.substr(start_index, length_of_substr);
*/

int main(){
    string temp = "Aayush Agrawal";
    string copy;
    for(int i=0;i<temp.size();i++){
        copy = copy + temp[i];
    }
    cout<<"copy = "<<copy;
    copy.clear();//clears the entire string
    cout<<"\ncopy = "<<copy;

    cout<<"\nto get substring of a string temp";

    string substr = temp.substr(7,7);// (start_index, length of substring)

    cout<<"\n the substring is "<<substr;
    
    return 0;
}
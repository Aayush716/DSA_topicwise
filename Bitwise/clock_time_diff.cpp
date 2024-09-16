/*
539. Minimum Time Difference
Solved
Medium
Topics
Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".

https://leetcode.com/problems/minimum-time-difference/description/

*/

class Solution {
public:
    int fun(string s){
        int hours = (s[0] - '0')*10 + (s[1]-'0');
        int minutes = (s[3] - '0')*10 + (s[4]-'0');
       // cout<<"hours = "<<hours<<" minutes = "<<minutes<<endl;
        minutes += hours*60;
        return minutes;
    }

    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int total_minutes = 24*60;
        multiset<int> s;
        for(int i=0;i<n;i++){
            int minutes = fun(timePoints[i]);
            s.insert(minutes);
        }

        vector<int> v;
        for(auto x: s){
            v.push_back(x);
            cout<<x<<"  ";
        }

        int ans = 1440;
        int n1 = v.size();
        for(int i=0;i<v.size()-1;i++){
            ans = min(ans,abs(v[i]-v[i+1]));
            // ans = min(ans,1440 - abs(v[i]-v[i+1]));
            // ans = min(ans,1440 - abs(v[i+1]-v[i]));
        }
        ans = min(ans,1440 - abs(v[n1-1]-v[0]));

        return ans;
    }
};


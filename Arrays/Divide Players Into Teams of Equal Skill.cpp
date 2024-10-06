/*
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
Example 2:

Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.

*/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n%2!=0){
            return -1;
        }
        sort(skill.begin(),skill.end());
        int target = skill[0] + skill[n-1];
       // cout<<"target = "<<target<<endl;
        long chemistry = skill[0]*skill[n-1];

        for(int i=1;i<n/2;i++){
          //  cout<<"skill[i] = "<<skill[i]<<" skills[n-1-i] = "<<skill[n-1-i]<<" total = "<<(skill[i]+skill[n-1-i])<<endl;
            if((skill[i]+skill[n-1-i])==target){
                chemistry += skill[i]*skill[n-1-i];
            }
            else{
                return -1;
            }
        }

        return chemistry;
    }
};
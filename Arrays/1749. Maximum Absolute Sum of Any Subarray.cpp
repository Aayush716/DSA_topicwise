class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum<0){
                sum = 0;
            }
            max_sum = max(max_sum,sum);
        }

        int min_sum = INT_MAX;
        sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum>0){
                sum=0;
            }
            min_sum = min(min_sum,sum);
        }

        if(max_sum>abs(min_sum)){
            return max_sum;
        }
        return abs(min_sum);
    }
};

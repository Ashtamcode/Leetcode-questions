class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0, n= nums.size(),ans=n+1;
        int sum =0;
        for(int right=0;right<n;right++){
            sum += nums[right];
            while(sum>=target){
                ans = min(ans,right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        if(ans==n+1){
            return 0;
        }else{
            return ans;
        }
    }
};
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int best = 1,incr = 1, dec = 1;
        for(int i=1;i<n;i++){
            if(nums[i-1] < nums[i] ){
                incr++;
            }else{
                incr = 1;
            }
            if(nums[i-1] > nums[i]){
                dec++;
            }else{
                dec = 1;
            }
            best = max({best,incr,dec});
        }
        return best;
    }
};
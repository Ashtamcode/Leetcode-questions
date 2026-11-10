class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0;
        for(int i=0;i<n;i++){
            int current_min = nums[i];
            int current_max = nums[i];
            for(int j=i;j<n;j++){
                current_min = min(current_min, nums[j]);
                current_max = max(current_max, nums[j]);
                
                total_sum += (current_max - current_min);
            }
        }
        return total_sum;
    }
};
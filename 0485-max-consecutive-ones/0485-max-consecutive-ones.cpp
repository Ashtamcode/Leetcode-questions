class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones=0,cr=0;
        for(int i=0;i<nums.size();i++){
                
            if(nums[i] == 1){ cr++;
            ones = max(ones,cr);
            }
            else{
            cr =0;
            }
        }
        return ones;
    }
};
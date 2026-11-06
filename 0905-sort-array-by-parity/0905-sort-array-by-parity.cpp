class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int r = 0;
        int l = nums.size() - 1;

        while (r < l) {
            if (nums[r] % 2 == 1 && nums[l] % 2 == 0) {
                swap(nums[r], nums[l]);
                r++;
                l--;
            } else if (nums[r] % 2 == 0) {
                r++;
            } else if (nums[l] % 2 == 1) {
                l--;
            }
        }

        return nums;
    }
};
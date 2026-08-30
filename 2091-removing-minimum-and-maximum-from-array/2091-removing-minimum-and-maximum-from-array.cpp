class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int ma = *max_element(nums.begin(),nums.end());
        int mi = *min_element(nums.begin(),nums.end());
        int ma_index,mi_index;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == ma) ma_index = i;
            if(nums[i] == mi) mi_index = i;
        }

        int i = min(ma_index,mi_index);
        int j = max(ma_index,mi_index);

        return min({j+1,n-i,(i+1)+(n-j)});
    }
};
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>a(nums.size()*2,0);
        for(int i=0;i<nums.size();i++){
            a[i] = nums[i];
            a[i+n] = nums[i];
        }
        return a;
    }
};
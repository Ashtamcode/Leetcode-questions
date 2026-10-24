class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>x;
        vector<int>y;
        for(int i=0;i<n;i++){
            x.push_back(nums[i]);
        }
        for(int i=n-1;i<n;i++){
            y.push_back(nums[i]);
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;

    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,1);
        vector<int>surfix(n,1);
        vector<int>ans(n);
        // prefix[0] = nums[0];
        // surfix[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i] =  prefix[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            surfix[i] = surfix[i+1] * nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i] = prefix[i] * surfix[i];
        }
        return ans;
    }
};
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefmax(n);
        prefmax[0] = nums[0];
        vector<int>prefmin(n);
        prefmin[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefmax[i] = max(prefmax[i-1],nums[i]); 
        }
        for(int i=n-2;i>=0;i--){
            prefmin[i] = min(prefmin[i+1],nums[i]);
        }
        int m=INT_MAX;
        for(int i=0;i<n;i++){
            if(prefmax[i]-prefmin[i] <=k){
                m = min(m,i);
            }
        }
        if(m == INT_MAX) return -1;
        return m;
    }
};
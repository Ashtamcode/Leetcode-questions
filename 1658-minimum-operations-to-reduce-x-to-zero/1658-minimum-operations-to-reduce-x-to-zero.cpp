class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        int target = total - x;
        int left = 0;
        int minsize = 0;
        int currsum = 0;
        if(total < x) return -1;
        if(target == 0) return n;
        for(int right=0;right<n;right++){
            currsum += nums[right];
            while(currsum >= target){
                if(currsum == target){
                    minsize =  max(minsize,right-left+1);
                }
                currsum -= nums[left];
                left++;
            }
        }
        if(minsize == 0) return -1;
        else return n - minsize;
    }
};
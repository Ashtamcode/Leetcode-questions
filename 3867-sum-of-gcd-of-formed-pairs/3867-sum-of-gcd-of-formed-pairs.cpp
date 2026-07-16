class Solution {
private:
    long long gcd(int a,int b ){
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int mxi = 0;
        long long sum =0;
        vector<int> prefixgcd(nums.size());
        for(int i=0;i<nums.size();i++){
            mxi = max(mxi,nums[i]);
            prefixgcd[i] = gcd(nums[i],mxi);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int n=prefixgcd.size();
       
        int l=0 ,r=n-1;
        while(r>l){
            sum += gcd(prefixgcd[r],prefixgcd[l]);
            l++;
            r--;
        }
       
        return sum;
    }
};
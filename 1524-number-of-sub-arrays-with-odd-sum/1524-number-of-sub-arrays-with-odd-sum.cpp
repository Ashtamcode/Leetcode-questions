class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // [1,2,3,4,5,6,7]
        // [1,3,6,10,15,21,28]
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int even = 1, odd = 0, prefix = 0, subarr = 0;
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            if (prefix % 2 == 1) {
                int added = even;
                subarr = (subarr +even)%MOD;
                odd++;
            } else {
                int added = odd;
                subarr = (subarr+odd)%MOD;
                even++;
            }
        }
        return subarr;
    }
};
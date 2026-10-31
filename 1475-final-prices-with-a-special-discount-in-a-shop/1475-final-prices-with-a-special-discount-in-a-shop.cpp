class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        for (int i = 0; i < n; i++) {
            int pr = prices[i];
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= pr) {
                    ans[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return ans;
    }
};
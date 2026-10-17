class Solution {
public:
    int digsum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> dig(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            dig[i] = digsum(nums[i]);
        }
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = dig[i];
        }
        auto comp = [&m](int a, int b) {
            if (m[a] == m[b])
                return a < b;
            return m[a] < m[b];
        };
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), comp);
        unordered_map<int, int> values;
        for (int i = 0; i < nums.size(); i++) {
            values[sorted[i]] = i;
        }
        vector<bool> visited(nums.size(), false);
        int cycles = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (visited[i]) {
                continue;
            }

            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;

                int next_element = nums[curr];
                curr = values[next_element];
            }
            cycles++;
        }
        return nums.size() - cycles;
    }
};
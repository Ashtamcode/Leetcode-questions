/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> bfs(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> lvl;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(lvl);
        }
        return ans;
    }

public:
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> ele = bfs(root);

        map<int, int> m;
        for (int i = 0; i < ele.size(); i++) {
            int sum = 0;
            for (int val : ele[i]) {
                sum += val;
            }
            m[i+1] = sum;
        }
        int maxi = INT_MIN;
        int minKey = INT_MAX;

        for (auto it : m) {
            if (it.second > maxi) {
                maxi = it.second;
                minKey = it.first;
            } else if (it.second == maxi) {
                minKey = min(minKey, it.first);
            }
        }
        return minKey;
    }
};
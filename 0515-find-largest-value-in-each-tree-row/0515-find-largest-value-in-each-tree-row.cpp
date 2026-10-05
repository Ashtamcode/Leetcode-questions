/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void bfs(TreeNode* root,vector<vector<int>>& bf){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>levl;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != nullptr)q.push(node->left);
                if(node->right != nullptr)q.push(node->right);
                levl.push_back(node->val);
            }
            bf.push_back(levl);
        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>bf;
        bfs(root,bf);
        vector<int>ans;
        for(auto it:bf){
            int max_ele = *max_element(it.begin(),it.end());
            ans.push_back(max_ele);
        }
        return ans;
    }
};
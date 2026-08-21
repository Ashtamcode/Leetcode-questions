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
 bool dfs(TreeNode* root,int cursum ,int& targetSum){
            if(root == NULL){
                return false;
            }
            cursum += root->val;
            if(!root->left && !root->right){
                return cursum == targetSum;
            }
            return dfs(root->left,cursum,targetSum) || dfs(root->right,cursum,targetSum);
            
        }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
       
        return dfs(root,0,targetSum);

    }
};
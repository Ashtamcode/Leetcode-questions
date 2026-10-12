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
    void inorder(TreeNode*root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
    
        if (ans.size() <= 1) return true;
        
       
        for (size_t i = 1; i < ans.size(); i++) {
            if (ans[i] <= ans[i - 1]) { 
                return false; 
            }
        }
        
        return true;
    }
};
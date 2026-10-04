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
    void inorder(TreeNode* root,vector<int>& in){
        if(root == NULL) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        set<int>s(in.begin(),in.end());
        if(s.size() <= 1) return -1;
        auto it = next(s.begin(), 1); 
        return *it;
    }
};
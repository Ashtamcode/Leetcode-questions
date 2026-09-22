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
    void inorder(TreeNode* root,vector<int>& ans){
        if(root == nullptr){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        vector<int>in;
        inorder(root,in);
        unordered_map<int,int>h;
        for(int i:in){
            h[i]++;
        }
        int maxfreq = 0;
        for(const auto&pair:h){
            if(pair.second > maxfreq){
                maxfreq = pair.second;
                ans.clear();
                ans.push_back(pair.first);
            }else if(pair.second ==  maxfreq){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};
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
    vector<vector<int>> bfs(TreeNode* root){
       
        vector<vector<int>> bfsans;
         if(root == nullptr){
            return bfsans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            int size = q.size();
            vector<int> col;
            for(int i=0;i<size;i++){
                
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                col.push_back(node->val);
            }
            bfsans.push_back(col);
            

        }
        return bfsans;
    }

    vector<vector<int>> reverse(vector<vector<int>> bfs){
        int size = bfs.size();
        vector<vector<int>> ans(size,vector<int>(bfs[0].size(),0));
        for(int i=0;i<size;i++){
            ans[i] = bfs[size-i-1];
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>>b = bfs(root);
        return reverse(b);
    }
};
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
    void markparent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    TreeNode* node(TreeNode*root,int start){
         if (root == nullptr)
        return nullptr;

    if (root->val == start)
        return root;

    TreeNode* left = node(root->left, start);
    if (left != nullptr)
        return left;

    return node(root->right, start);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int minutes = 0;
        unordered_map<TreeNode*,TreeNode*> parent;
        markparent(root,parent);
        TreeNode* curr = node(root,start);
        unordered_map<TreeNode*,bool> visited;
        visited[curr] = true;
        queue<TreeNode*>q;
        q.push(curr);
        while(!q.empty()){
            int size = q.size();
            int flag =0;
            for(int i=0;i<size;i++){
                TreeNode* now = q.front();
                q.pop();
                if(now->left && !visited[now->left]){
                    flag =1;
                    visited[now->left] = true;
                    q.push(now->left);
                }
                if(now->right && !visited[now->right]){
                    flag =1;
                    visited[now->right] = true;
                    q.push(now->right);
                }
                if(parent[now] && !visited[parent[now]]){
                    flag =1;
                    visited[parent[now]] = true;
                    q.push(parent[now]);
                }
            }
            if(flag) minutes++;
        }
        return minutes;
    }
};
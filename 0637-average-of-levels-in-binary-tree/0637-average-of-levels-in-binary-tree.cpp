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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>>bfs;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>lvl;
            for(int i=0;i<size;i++){
               
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right)q.push(curr->right);
                lvl.push_back(curr->val);
            }
            bfs.push_back(lvl);
            
        }
        vector<double>a;
        for(auto lvl:bfs){
            double avg=0;
            for(auto ele:lvl){
                avg+=ele;
            }
            double avgs = avg / lvl.size();
            a.push_back(avgs);
        }
        return a;
    }
};
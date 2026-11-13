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
    int minswaps(vector<int>&lvl){
        int swaps = 0;
        vector<int>sor = lvl;
        sort(sor.begin(),sor.end());
        map<int,int>m;
        for(int i=0;i<lvl.size();i++){
            m[lvl[i]] = i;
        }
        for(int i=0;i<lvl.size();i++){
            if(sor[i] == lvl[i]) continue;

            int currindex = m[sor[i]];
            m[lvl[i]] = currindex;
            swap(lvl[currindex],lvl[i]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int totalswaps =0 ;
        while(!q.empty()){
            int size = q.size();
            vector<int>lvl;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            totalswaps += minswaps(lvl);
        }
        return totalswaps;
    }
};
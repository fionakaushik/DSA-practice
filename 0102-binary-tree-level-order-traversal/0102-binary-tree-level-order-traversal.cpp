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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //ans list:
        vector<vector<int>>ans;
        if(root==NULL) return {};
        //ue a queue(fifo) that stores nodes
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size(); //to determine the no.of times loop should run
            vector<int>level;   //for each level each;
            for( int i=0;i<size;i++)
            {
                TreeNode* node=q.front(); //3
                q.pop();
                if(node->left !=NULL) q.push(node->left);  //9
                if(node->right !=NULL) q.push(node->right);  //20

                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;

    }
};
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr)return nullptr;
        helper(root->left,root->right,1);
        return root;
    }
private:
    void helper(TreeNode* left, TreeNode* right,int level){
        if(left && right){
            if(level%2!=0){
                int t = left->val;
                left->val=right->val;
                right->val=t;
            }
            helper(left->left,right->right,level+1);
            helper(left->right,right->left,level+1);
        }
    }
};
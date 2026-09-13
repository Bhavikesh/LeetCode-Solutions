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
    vector<int> inorderTraversal(TreeNode* root) {
        // morris traversal

        TreeNode* curr = root;

        vector<int> res;

        while(curr != NULL){
            if(curr->left ==NULL){
                // l , v , r
                res.push_back(curr->val);
                curr = curr -> right;
            }else{
                TreeNode* leftChild = curr -> left;

                while(leftChild->right != NULL){
                    leftChild = leftChild->right;
                }

                leftChild -> right = curr;
                // pont the left side of curr to null so that infinite loop ignored
                TreeNode* temp = curr;
                curr = curr -> left;
                temp -> left = NULL;
            }
        }
        return res;
    }
};
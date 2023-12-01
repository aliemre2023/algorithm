// Time Complexity = O(log(n))
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/insert-into-a-binary-search-tree/

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

    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *traverser = root;
        TreeNode *new_node = new TreeNode(val);

        if(root == nullptr){
            root = new_node;
        }
        while(traverser){
            if(traverser->val > val){
                if(traverser->left != nullptr){
                    traverser = traverser->left;
                }
                else{
                    traverser->left = new_node;
                    break;
                }
            }
            else{
                if(traverser->right != nullptr){
                    traverser = traverser->right;
                }
                else{
                    traverser->right = new_node;
                    break;
                }
            }
        }
        return root;
    }
};
// Time Complexity = O(log(n))
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root != nullptr){
            if(key < root->val) root->left = deleteNode(root->left, key);
            else if(key > root->val) root->right = deleteNode(root->right, key);
            else{
                if(root->left == nullptr && root->right == nullptr) 
                    return nullptr;          
                if (root->left == nullptr || root->right == nullptr)
                    return root->left != nullptr ? root->left : root->right;    
					                                               
                TreeNode* l_righthold = root->left;                        
                while(l_righthold->right != nullptr) l_righthold = l_righthold->right;    
                root->val = l_righthold->val;                            
                root->left = deleteNode(root->left, l_righthold->val);
            }
        }
        return root;
    }
};
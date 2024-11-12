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
/*
Plan -> get max in left bt, get min in right bt and check order
*/
    int getMaxLeft(TreeNode* root) {
        if(!root) {
            return INT_MIN;
        }
        return max(max(getMaxLeft(root->left), root->val), getMaxLeft(root->right));
    }

    int getMinRight(TreeNode* root) {
        if(!root) {
            return INT_MAX;
        }
        return min(min(getMinRight(root->left), root->val), getMinRight(root->right));
    }

    bool isValidBST(TreeNode* root) {
        if(!root || (!root->right && !root->left)) {
            return true;
        }
        if(getMaxLeft(root->left) >= root->val || getMinRight(root->right) <= root->val) {
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};

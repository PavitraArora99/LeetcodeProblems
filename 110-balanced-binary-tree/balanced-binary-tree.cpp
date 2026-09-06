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
    class Pair {
    public:
        int height;
        bool balanced;
    };

    Pair checkBalance(TreeNode* root) {
        Pair p;
        if (root == NULL) {
            p.height = 0;
            p.balanced = true;
            return p;
        }

        Pair left = checkBalance(root->left);
        Pair right = checkBalance(root->right);

        p.height = max(left.height, right.height) + 1;
        
        if (abs(left.height - right.height) <= 1 && left.balanced && right.balanced) {
            p.balanced = true;
        } else {
            p.balanced = false;
        }

        return p;
    }
public:
    bool isBalanced(TreeNode* root) {
        Pair ans = checkBalance(root);
        return ans.balanced;
    }
};
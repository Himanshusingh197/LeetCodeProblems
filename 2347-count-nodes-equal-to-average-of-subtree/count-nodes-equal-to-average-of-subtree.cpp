class Solution {
public:

    int findSum(TreeNode* root, int &count) {
        if(root == NULL) {
            return 0;
        }

        count++;

        int lSum = findSum(root->left, count);
        int rSum = findSum(root->right, count);

        return lSum + rSum + root->val;
    }

    int solve(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int count = 0;

        int sum = findSum(root, count);

        int result = 0;

        if(root->val == sum / count) {
            result += 1;
        }

        result += solve(root->left);
        result += solve(root->right);

        return result;
    }

    int averageOfSubtree(TreeNode* root) {
        return solve(root);
    }
};
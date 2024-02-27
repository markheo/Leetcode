/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pseudoPalindromicPathsRecursive(struct TreeNode* node, int count[]) {
    if (!node) return 0;
    
    // Toggle the count for this node's value
    count[node->val] ^= 1;
    
    int ans = 0;
    // If it's a leaf node, check if the path is pseudo-palindromic
    if (!node->left && !node->right) {
        int oddCounts = 0;
        for (int i = 1; i <= 9; i++) {
            if (count[i] % 2 != 0) oddCounts++;
        }
        if (oddCounts <= 1) ans = 1;  // Path is pseudo-palindromic
    } else {
        // Continue to child nodes
        ans += pseudoPalindromicPathsRecursive(node->left, count);
        ans += pseudoPalindromicPathsRecursive(node->right, count);
    }
    
    // Toggle the count back for this node's value
    count[node->val] ^= 1;
    
    return ans;
}

int pseudoPalindromicPaths (struct TreeNode* root) {
    int count[10] = {0};  // Count of node values from 1 to 9
    return pseudoPalindromicPathsRecursive(root, count);
}
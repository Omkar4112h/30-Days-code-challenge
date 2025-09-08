#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    
    bool check(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;  
        if (node->val <= minVal || node->val >= maxVal) return false;  
        return check(node->left, minVal, node->val) && 
               check(node->right, node->val, maxVal);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution s;
    cout << (s.isValidBST(root) ? "true" : "false") << endl; 
}

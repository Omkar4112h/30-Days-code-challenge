#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();

            if (!t1 && !t2) continue;
            if (!t1 || !t2 || t1->val != t2->val) return false;

            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    vector<TreeNode*> nodes(arr.size(), nullptr);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != -1)  
            nodes[i] = new TreeNode(arr[i]);
    }

    for (int i = 0; i < arr.size(); i++) {
        if (nodes[i]) {
            int leftIdx = 2 * i + 1;
            int rightIdx = 2 * i + 2;
            if (leftIdx < arr.size()) nodes[i]->left = nodes[leftIdx];
            if (rightIdx < arr.size()) nodes[i]->right = nodes[rightIdx];
        }
    }
    return nodes[0];
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = buildTree(arr);

    Solution sol;
    if (sol.isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is Not Symmetric" << endl;

    return 0;
}

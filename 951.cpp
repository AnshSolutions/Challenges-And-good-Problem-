#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
     if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) ||
           (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
}
TreeNode* insertNode(int val) {
    if (val == -1) {
        return nullptr;
    }
    return new TreeNode(val);
}
TreeNode* buildTree(int nodes[], int n, int& index) {
    if (index >= n || nodes[index] == -1) {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, n, index);
    root->right = buildTree(nodes, n, index);

    return root;
}

int main() {
    int n;

    cin >> n;
    int tree1Nodes[n];
    for (int i = 0; i < n; i++) {
        cin >> tree1Nodes[i];
    }

    int index1 = 0;
    TreeNode* root1 = buildTree(tree1Nodes, n, index1);

    cin >> n;
    int tree2Nodes[n];
    for (int i = 0; i < n; i++) {
        cin >> tree2Nodes[i];
    }

    int index2 = 0;
    TreeNode* root2 = buildTree(tree2Nodes, n, index2);

    bool result = flipEquiv(root1, root2);

    if (result) {
        cout << "The trees are flip equivalent.\n";
    } else {
        cout << "The trees are not flip equivalent.\n";
    }

    return 0;
}


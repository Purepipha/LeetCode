/*
 * Define a binary tree class for LeetCode Debug
 * Author: Purepipha
 * Create: 2022-09-06
 */

#include <vector>
#include <stack>
#include <queue>

constexpr int null = -1; // null 的值，应该改为 node->val 不会取到的一个值

using std::vector;
using std::queue;
using std::stack;

// definition of TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// definition of Tree
class Tree {
public:
    Tree() : root(nullptr) {}
    ~Tree();
    Tree(const vector<int>& data) { CreateTree(data); }
    void CreateTree(const vector<int>& data);
    TreeNode* Root() { return root; }
private :
    TreeNode *root;
};

// transform vector to a binary tree
void Tree::CreateTree(const vector<int>& data)
{
    if (data.size() == 0) {
        root = nullptr;
    }
    queue<TreeNode *> que;
    root = new TreeNode(data[0]);
    que.push(root);
    int indexData = 1;
    while (!que.empty() && indexData < data.size()) {
        TreeNode *curNode;
        if (!que.empty()) {
            curNode = que.front();
        }
        que.pop();
        if (data[indexData] != null) {
            TreeNode* left = new TreeNode(data[indexData]);
            curNode->left = left;
            que.push(left);
        }
        ++indexData;
        if (indexData < data.size() && data[indexData] != null) {
            TreeNode* right = new TreeNode(data[indexData]);
            curNode->right = right;
            que.push(right);
        }
        ++indexData;
    }
}

// delete the tree
Tree::~Tree()
{
    stack<TreeNode*> st;
    if (root == nullptr) {
        return;
    }
    st.push(root);
    while (!st.empty()) {
        TreeNode *curNode = st.top();
        if (curNode) {
            st.push(nullptr);
            if (curNode->right) {
                st.push(curNode->right);
            }
            if (curNode->left) {
                st.push(curNode->left);
            }
        } else {
            st.pop();
            curNode = st.top();
            st.pop();
            delete curNode;
        }
    }
    root = nullptr;
}
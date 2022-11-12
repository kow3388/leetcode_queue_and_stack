#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//recursive做dfs
void inorder(TreeNode *root, vector<int> &ans)
{
    if(!root)
        return;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    
    return ans;
}

//stack做dfs
vector<int> inorderTraversal1(TreeNode *root)
{
    if(!root)
        return {};
    
    vector<int> ans;
    stack<pair<TreeNode*, bool>> s;
    s.push({root, true});

    while(!s.empty())
    {
        auto tmp = s.top();

        if(tmp.second and tmp.first->left)
        {
            s.pop();
            s.push({tmp.first, false});
            s.push({tmp.first->left, true});
            continue;
        }

        ans.push_back(tmp.first->val);
        s.pop();

        if(tmp.first->right)
            s.push({tmp.first->right, true});
    }
    
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = inorderTraversal1(root);
    for(int a : ans)
        cout << a << endl;

    return 0;
}
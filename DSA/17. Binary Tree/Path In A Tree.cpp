#include <bits/stdc++.h> 

bool getPath(TreeNode<int> *root, int x, vector<int>& ans){
    if(root == NULL)
        return false;

    ans.push_back(root->data);

    if(root->data == x){
        return true;
    }

    //if any side reuturns true, then return true
    if(getPath(root->left, x, ans) || getPath(root->right, x, ans))
        return true;

    ans.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    getPath(root, x, ans);

    return ans;
}

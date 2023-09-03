#include <bits/stdc++.h> 
vector<int> solve(TreeNode* root){
    if(root == NULL){
        return {1, 0, INT_MAX, INT_MIN};
    }
    if(!root->left && !root->right){
        return {1, 1, root->data, root->data};
    }
    
    auto l = solve(root->left);
    auto r = solve(root->right);
    //{bst/not , size, min, max}
    if(l[0] == 1 && r[0] == 1){
        if(root->data > l[3] && root->data < r[2]){
            int x = l[2]; //min of left
            int y =  r[3]; //max of right

            if(x == INT_MAX) x = root->data;
            if(y == INT_MIN) y = root->data;

            return {1, l[1]+r[1]+1, x, y};
        }
    }
    return {0, max(l[1], r[1]), 0, 0};
}
int largestBST(TreeNode* root) 
{
    vector<int> ans = solve(root);
    return ans[1];
}

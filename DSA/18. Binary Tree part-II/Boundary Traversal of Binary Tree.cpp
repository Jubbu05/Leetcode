#include <bits/stdc++.h>

vector<int> ans;

bool isLeaf(TreeNode<int> *root){
    return root->left==NULL && root->right==NULL;
}

void addleft(TreeNode<int> *root){
    if(root == NULL || isLeaf(root)){
        return;
    }
    
    ans.push_back(root->data);
    if(root->left){
        addleft(root->left);
    }
    else{
        addleft(root->right);
    }
}

void addRight(TreeNode<int> *root){
    if(root == NULL || isLeaf(root)){
        return;
    }
    
    if(root->right){
        addRight(root->right);
    }
    else{
        addRight(root->left);
    }
    ans.push_back(root->data);
}

void addLeaf(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    if(isLeaf(root)){
        ans.push_back(root->data);
    }
    addLeaf(root->left);
    addLeaf(root->right);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    addleft(root->left);
    addLeaf(root->left);
    addLeaf(root->right);
    addRight(root->right);

    return ans;
}

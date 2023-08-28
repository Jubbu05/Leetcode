void solve(BinaryTreeNode<int> * root, vector <string>& ans, string s){
    if(root == NULL){
        return;
    }

    s+= to_string(root->data) + " ";
    if(root->left == NULL && root->right == NULL){
        ans.push_back(s);
        return;
    }
    solve(root->left, ans, s);
    solve(root->right, ans, s);
}
vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector <string> ans;
    string s = "";
    solve(root, ans, s);
    return ans;
}
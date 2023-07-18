// first preference is height, if height is same then preference is sum
class Solution
{
public:
    vector<int> solve(Node* root){
        //{height, sum}
        if(!root) return {0,0};
        vector<int> a = solve(root->left);
        vector<int> b = solve(root->right);

        if(a[0]>b[0]) return {a[0]+1, a[1]+root->data}; // left height is more
        if(a[0]<b[0]) return {b[0]+1, b[1]+root->data}; // right height is more

        else return {a[0]+1, max(a[1],b[1])+root->data}; // both height are same so return whose sum is more
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        vector<int> ans = solve(root);
        return ans[1];
    }
};
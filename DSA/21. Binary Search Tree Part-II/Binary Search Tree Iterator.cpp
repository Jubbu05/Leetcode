class BSTIterator
{
private:
    stack<TreeNode *> myStack;
    // void pushAll(TreeNode *node)
    // {
    //     for (; node != NULL; myStack.push(node), node = node->left);
    // }
    void pushAll(TreeNode* root){
        while(root != NULL){
            myStack.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }
};
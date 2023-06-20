#include <bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> res;
    vector<int> pre, in, post;
    stack<pair<BinaryTreeNode<int> *, int>> st;

    st.push({root, 1});

    if (root == NULL)
        return res;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is part of preorder
        // increment it.second
        // push the left side of the tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        // this is part of inorder
        // increment it.second
        // push the right side of the tree
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }

        // postorder
        else
        {
            post.push_back(it.first->data);
        }
    }

    res.push_back(in);
    res.push_back(pre);
    res.push_back(post);

    return res;
}
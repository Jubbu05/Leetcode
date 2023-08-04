// Time - o(n)
// Space - o(1)

float findMedian(struct Node *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    Node *curr = root, *pre, *prev;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            count++;
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    curr = root;
    int c = 0;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            c++;
            if (count % 2 != 0 && c == (count + 1) / 2)
                return curr->data;
            else if (count % 2 == 0 && c == (count / 2) + 1)
                prev = curr;
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                c++;
                if (count % 2 == 0 && c == count / 2)
                    prev = curr;
                if (count % 2 == 0 && c == (count / 2) + 1)
                    return (prev->data + curr->data) / 2.0;
                else if (count % 2 != 0 && c == (count + 1) / 2)
                    return curr->data;
                prev = curr;
                curr = curr->right;
            }
        }
    }
}
class Solution
{
public:
    // function to construct tree from string
    Node *solve(string s, int &idx)
    {
        if (idx >= s.length())
        {
            return NULL;
        }
        string str = "";
        while (s[idx] >= '0' && s[idx] <= '9')
        {
            str += s[idx];
            idx++;
        }
        Node *ans = new Node(stoi(str));
        if (s[idx] == '(')
        {
            idx++;
            ans->left = solve(s, idx);
        }
        if (s[idx] == '(')
        {
            idx++;
            ans->right = solve(s, idx);
        }
        idx++;
        return ans;
    }

    Node *treeFromString(string str)
    {
        int idx = 0;
        return solve(str, idx);
    }
};
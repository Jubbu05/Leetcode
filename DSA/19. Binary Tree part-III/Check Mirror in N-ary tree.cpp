class Solution
{
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        unordered_map<int, stack<int>> m; // corresponding to each node, we will store a stack of its children
        for (int i = 0; i < 2 * e; i += 2)
        {
            // In A
            // 1 2 1 3 1 4

            //   1
            // 2 3 4
            m[A[i]].push(A[i + 1]); // 1 -> [2, 3, 4]
        }

        for (int i = 0; i < 2 * e; i += 2)
        {
            // In B
            // 1 4 1 3 1 2 -> If it's mirror then it should be this
            if (m[B[i]].top() != B[i + 1])
                return 0;

            m[B[i]].pop();
        }
        return 1;
    }
};
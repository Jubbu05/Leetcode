// 0 base indexing
// left - 2 * i + 1
// right - 2 * i + 2    

class Solution {
public:
    int widthOfBinaryTree(TreeNode * root) {
      if (root == NULL) return 0;
      long ans = 0;
      queue<pair<TreeNode*, int>> q;
      q.push({root,0});
      while (!q.empty()) {
        int size = q.size();
        long leftMost = q.front().second;
        long rightMost = q.back().second;
        ans = max(ans, rightMost - leftMost + 1);
        for (int i = 0; i < size; i++) {
          TreeNode * temp = q.front().first;
          long cur_id = q.front().second;
          q.pop();
          if (i == 0) leftMost = cur_id;
          if (i == size - 1) rightMost = cur_id;
          if (temp -> left) q.push({temp -> left, cur_id * 2 + 1});
          if (temp -> right) q.push({temp -> right, cur_id * 2 + 2});
        }
      }
      return ans;
    }
};
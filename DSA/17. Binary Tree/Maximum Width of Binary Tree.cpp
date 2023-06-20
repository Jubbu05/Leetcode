// 0 base indexing
// left - 2 * i + 1
// right - 2 * i + 2    

class Solution {
public:
    int widthOfBinaryTree(TreeNode * root) {
      if (root == NULL) return 0;
      int ans = 0;
      queue<pair<TreeNode*, int>> q;
      q.push({root,0});
      while (!q.empty()) {
        int size = q.size();
        int curMin = q.front().second;
        int leftMost, rightMost;
        for (int i = 0; i < size; i++) {
          long long cur_id = q.front().second - curMin; // subtracted to prevent integer overflow curMin is min index of that level
          TreeNode * temp = q.front().first;
          q.pop();
          if (i == 0) leftMost = cur_id;
          if (i == size - 1) rightMost = cur_id;
          if (temp -> left) q.push({temp -> left, cur_id * 2 + 1});
          if (temp -> right) q.push({temp -> right, cur_id * 2 + 2});
        }
        ans = max(ans, rightMost - leftMost + 1);
      }
      return ans;
    }
};
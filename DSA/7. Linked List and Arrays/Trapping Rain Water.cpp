class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        for (int i = 0; i < n; i++){
            int j = i;
            int leftMax = 0, rightMax = 0;
             while (j >= 0) {
              leftMax = max(leftMax, height[j]);
              j--;
            }
            j = i;
            while (j < n) {
              rightMax = max(rightMax, height[j]);
              j++;
            }
            waterTrapped += min(leftMax, rightMax) - height[i];
        }
        return waterTrapped;
    }
};

//------------------------------------------------------------------------------------

class Solution {
public:
    int trap(vector < int > & height) {
      int n = height.size();
      int left = 0, right = n - 1;
      int res = 0;
      int maxLeft = 0, maxRight = 0;
      while (left <= right) {
        if (height[left] <= height[right]) {
          if (height[left] >= maxLeft) {
            maxLeft = height[left];
          } else {
            res += maxLeft - height[left];
          }
          left++;
        } else {
          if (height[right] >= maxRight) {
            maxRight = height[right];
          } else {
            res += maxRight - height[right];
          }
          right--;
        }
      }
      return res;
    }
};

//------------------------------------------------------------------------------------
// prefix contains max left->right
// suffix contains max right->left

class Solution {
public:
    int trap(vector < int > & arr) {
      int n = arr.size();
      int prefix[n], suffix[n];
      prefix[0] = arr[0];
      for (int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i - 1], arr[i]);
      }
      suffix[n - 1] = arr[n - 1];
      for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i + 1], arr[i]);
      }
      int waterTrapped = 0;
      for (int i = 0; i < n; i++) {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
      }
      return waterTrapped;
    }
};
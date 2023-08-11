class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int max_area = 0;

        while(left < right){
            int lh = height[left];
            int rh = height[right];
            int len = right - left;

            int curr_area = min(lh, rh) * len;
            max_area = max(max_area, curr_area);

            if(lh < rh){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};
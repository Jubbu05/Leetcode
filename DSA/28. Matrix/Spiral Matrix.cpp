// direction -
//     0 left to right
//     1 top to bottom
//     2 right to left
//     3 bottom to top
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int t = 0;
        int b = n-1;
        int l = 0;
        int r = m-1;
        int dir=0;
        int i;
        vector<int> ans;

        while(t <= b && l <= r){
            if(dir == 0){
                for(i = l; i<=r; i++){
                    ans.push_back(matrix[t][i]);
                }
                t++;
            }
            else if(dir == 1){
                for(i = t; i<=b; i++){
                    ans.push_back(matrix[i][r]);
                }
                r--;
            }
            else if(dir == 2){
                for(i = r; i>=l; i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }
            else{
                for(i = b; i>= t; i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
            dir = (dir+1) % 4;
        }
        return ans;
    }
};
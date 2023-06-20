class Solution {
public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j] == target)
//                     return true;
//             }
//         }
//         return false;
//     }
 
//------------------------------------------------------------------------------------
    
    // pointer at 1st row lase element i.e 7
    // start searching 
    // if target < elemrnt move left
    // if target > elemrnt move down
    // do until pointer is out of bound
    
    // bool searchMatrix(vector<vector<int>>& matrix, int target){
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     int i=0, j=m-1;
    //     while(i<n && j>=0){
    //         if(matrix[i][j] == target) return true;
    //         if(matrix[i][j] > target) j--;
    //         else i++;
    //     }
    //     return false;
    // }
    
//------------------------------------------------------------------------------------
    
    
//     Binary search on each row
    
//     mid = (low + high) / 2
   
//     if mid[value] < target low = mid + 1
//     if mid[value] > target high = mid -1 1
        
//     imaginery index 
//     find(i,j)
//     i = mid / m
//     j = mid % m
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        if(n == 0) return false;
        int hi = (n * m) - 1;
        
        while(lo <= hi) {
            int mid = (lo + hi)  / 2;
            if(matrix[mid/m][mid % m] == target) {
                return true;
            }
            if(matrix[mid/m][mid % m] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
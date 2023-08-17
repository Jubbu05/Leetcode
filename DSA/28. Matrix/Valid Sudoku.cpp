// BOX = (Row/3)*3 + (Col/3)

// HashSet
// "Row + Index + Number"
// "Col + Index + Number"
// "Box + Index + Number"

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_set<string> seen;
//         for(int i=0; i<9; i++){
//             for(int j=0; j<9; j++){
//                 if(board[i][j] != '.'){
//                     if(!seen.insert("row" + i + board[i][j]) || !seen.insert("col" + j + board[i][j])) return false;
//                     if(!seen.insert("box" + ((i/3)*3 + (j/3)) + board[i][j])) return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_map<string,int>hash;
//         for(int row=0;row<9;row++){
//             for(int col=0;col<9;col++){
//                 if(board[row][col] != '.')
//                 {
    
//                     string r = "row"+to_string(row)+to_string(board[row][col]);
//                     string c = "col"+to_string(col)+to_string(board[row][col]);
//                     int b = (row/3) * 3 + (col/3);
//                     string box= "box"+ to_string(b) + to_string(board[row][col]);

//                     if(hash[r] != 1 && hash[c] != 1 && hash[box] != 1){
//                         hash[r]=1;
//                         hash[c]=1;
//                         hash[box]=1;
//                     }else{
//                         return false;
//                     }

//                     }
                
//             }
//         }
        
//         return true;
//     }
// };

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), blocks(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') continue;
                
                int curr = board[i][j] - '0';
                if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i/3)*3+j/3].count(curr)) 
                    return false;
                
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i/3)*3+j/3].insert(curr);
            }
        }
        
        return true;
    }
};
// moving left -> (vertical - 1, level + 1)
// moving right -> (vertical + 1, level + 1)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          // map(vertical,levels, nodes) using multiset for nodes coz nodes can be of same value 
          map<int, map<int, multiset<int>>> nodes;
          // queue(node,vertical,levels)
          queue<pair<TreeNode* , pair<int, int>>> todo;
        
          todo.push({root,{0,0}}); //initial vertical and level
        
          while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;

            //x -> vertical , y->level
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val); //inserting to multiset

            if (node -> left) {
              todo.push({node -> left,{x - 1,y + 1}});
            }
            if (node -> right) {
              todo.push({node -> right,{x + 1,y + 1}});
            }
          }

          vector<vector<int>> ans;
          for (auto p: nodes) {
            vector<int> col;
            for (auto q: p.second) { // p.second -> map<int, multiset<int>>
              col.insert(col.end(), q.second.begin(), q.second.end()); // q.second -> multiset<int> inserting from back
            }
            ans.push_back(col);
          }
          return ans;
    }
};
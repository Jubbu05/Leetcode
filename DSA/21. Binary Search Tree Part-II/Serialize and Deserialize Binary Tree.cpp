class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            
            // Append '#' if current node is NULL, otherwise append the node's value
            if(curNode==NULL) s.append("#,");
            else s.append(to_string(curNode->val)+',');
            
            // Enqueue the left and right child nodes (even if they are NULL)
            if(curNode!=NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        
        // Extract the value of the root node from the serialized data
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
    
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            // Deserialize the left child of the current node
            getline(s, str, ',');
            if(str == "#"){
               node->left == NULL; 
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            // Deserialize the right child of the current node
            getline(s, str, ',');
            if(str == "#"){
               node->right == NULL; 
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

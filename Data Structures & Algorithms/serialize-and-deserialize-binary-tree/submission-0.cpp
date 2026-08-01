/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr) s.append("#,");
            else{
                s.append(to_string(curr->val)+",");
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode*  root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode*  node= q.front();
            q.pop();

            if(getline(ss,str,',')){
                if (str!="#"){
                    node->left=new TreeNode(stoi(str));
                    q.push(node->left);
                }
            }

            if(getline(ss,str,',')){
                if (str!="#"){
                    node->right=new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }
        return root;
        
    }
};
